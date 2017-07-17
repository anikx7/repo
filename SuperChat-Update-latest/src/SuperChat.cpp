#include <signal.h>
#include <assert.h>
//#include <ncurses.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <FL/Fl.H>
#include<FL/Fl_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include<FL/Fl_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include<FL/Fl_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include<FL/Fl_Secret_Input.H>
#include <FL/Fl_Scroll.H>
#include<FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include <FL/Fl_Multiline_Output.H>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "DDSEntityManager.h"
#include "ccpp_SuperChat.h"
#include <thread>
#include "nicks.h"

// This code is derived from the PrismTech HelloWorld examples

// You can include this code freely in your project.  Or not.

// This example program will show how to publish and subscribe
// to the data items used in SuperChat.

// It can be modified easily to provide data for software testing and
// debugging.

const bool sendChatroom = true;
const bool sendMsg = true;
const bool sendUser = true;
const bool recvChatroom = true;
const bool recvUser = true;
const bool recvMsg = true;


using namespace DDS;
using namespace SuperChat;

// these classes abstract out the sending and recieving of topics
// perhaps with some cleverness, generics could be used to eliminate
// some of the code

typedef std::vector<chatroom> chatroom_list_t;
typedef std::vector<message> message_list_t;
typedef std::vector<user> user_list_t;

void send_cb(Fl_Widget* w, void* p);
void exit_cb(Fl_Widget* w, void* p);

class chatroom_data
{
  private:
  DDSEntityManager em;
  chatroomDataWriter_var Writer;
  chatroomDataReader_var Reader;
  public:
  void send ( chatroom messageInstance )
  {
     ReturnCode_t status = Writer->write(messageInstance, DDS::HANDLE_NIL);
     checkStatus(status, "Writer::write");
  }
  void recv ( chatroom_list_t* chatroomList )
  {
     // if any data is available, it returns a list
     assert ( chatroomList );
     chatroomSeq msgList;
     SampleInfoSeq infoSeq;
     ReturnCode_t status =  - 1;
     status = Reader->take ( msgList, infoSeq, LENGTH_UNLIMITED,
                             ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE );
     checkStatus(status, "msgDataReader::take");
     for (DDS::ULong j = 0; j < msgList.length(); j++)
     {
       chatroomList->push_back ( msgList[j] );
     }
     status = Reader->return_loan ( msgList, infoSeq );
     checkStatus(status, "MsgDataReader::return_loan");
  }
  chatroom_data (char *topic_name)
  {
    // participant
    em.createParticipant ("");

    // create types
    chatroomTypeSupport_var T = new chatroomTypeSupport ();
    em.registerType ( T.in() );

    // create Topic
    em.createTopic ( topic_name );

    // create Publisher
    em.createPublisher ();

    // create dataWriter
    em.createWriter ( false );
    DataWriter_var dwriter = em.getWriter ();
    Writer = chatroomDataWriter::_narrow ( dwriter.in() );

    //create Subscriber
    em.createSubscriber ();

    // create DataReader
    em.createReader ();
    DataReader_var dreader = em.getReader ();
    Reader = chatroomDataReader::_narrow( dreader.in () );
    checkHandle( Reader.in (), "MsgDataReader::_narrow" );
  }
  ~chatroom_data ()
  {
    // Remove the DataWriters.
    em.deleteWriter ();

    // Remove the DataReaders
    em.deleteReader ();

    // Remove the Publisher.
    em.deletePublisher ();

    // Remove the Subscriber.
    em.deleteSubscriber ();

    // Remove the Topics.
    em.deleteTopic ();

    // Remove Participant.
    em.deleteParticipant ();
  }
};

class message_data
{
  private:
  DDSEntityManager em;
  messageDataWriter_var Writer;
  messageDataReader_var Reader;
  public:
  void send ( message messageInstance )
  {
     ReturnCode_t status = Writer->write(messageInstance, DDS::HANDLE_NIL);
     checkStatus(status, "Writer::write");
  }
  void recv ( message_list_t* messageList )
  {
     // if any data is available, it returns a list
     assert ( messageList );
     messageSeq msgList;
     SampleInfoSeq infoSeq;
     ReturnCode_t status =  - 1;
     status = Reader->take ( msgList, infoSeq, LENGTH_UNLIMITED,
                             ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE );
     checkStatus(status, "msgDataReader::take");
     for (DDS::ULong j = 0; j < msgList.length(); j++)
     {
       messageList->push_back ( msgList[j] );
     }
     status = Reader->return_loan ( msgList, infoSeq );
     checkStatus(status, "MsgDataReader::return_loan");
  }
  message_data (char *topic_name)
  {
    // participant
    em.createParticipant ("");

    // create types
    messageTypeSupport_var T = new messageTypeSupport ();
    em.registerType ( T.in() );

    // create Topic
    em.createTopic ( topic_name );

    // create Publisher
    em.createPublisher ();

    // create dataWriter
    em.createWriter ( false );
    DataWriter_var dwriter = em.getWriter ();
    Writer = messageDataWriter::_narrow ( dwriter.in() );

    //create Subscriber
    em.createSubscriber ();

    // create DataReader
    em.createReader ();
    DataReader_var dreader = em.getReader ();
    Reader = messageDataReader::_narrow( dreader.in () );
    checkHandle( Reader.in (), "MsgDataReader::_narrow" );
  }
  ~message_data ()
  {
    // Remove the DataWriters.
    em.deleteWriter ();

    // Remove the DataReaders
    em.deleteReader ();

    // Remove the Publisher.
    em.deletePublisher ();

    // Remove the Subscriber.
    em.deleteSubscriber ();

    // Remove the Topics.
    em.deleteTopic ();

    // Remove Participant.
    em.deleteParticipant ();
  }
};

class user_data
{
  private:
  DDSEntityManager em;
  userDataWriter_var Writer;
  userDataReader_var Reader;
  public:
  void send ( user userInstance )
  {
     ReturnCode_t status = Writer->write(userInstance, DDS::HANDLE_NIL);
     checkStatus(status, "Writer::write");
  }
  void recv ( user_list_t* userList )
  {
     // if any data is available, it returns a list
     assert ( userList );
     userSeq msgList;
     SampleInfoSeq infoSeq;
     ReturnCode_t status =  - 1;
     status = Reader->take ( msgList, infoSeq, LENGTH_UNLIMITED,
                             ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE );
     checkStatus(status, "msgDataReader::take");
     for (DDS::ULong j = 0; j < msgList.length(); j++)
     {
       userList->push_back ( msgList[j] );
     }
     status = Reader->return_loan ( msgList, infoSeq );
     checkStatus(status, "MsgDataReader::return_loan");
  }
  user_data (char *topic_name)
  {
    // participant
    em.createParticipant ("");

    // create types
    userTypeSupport_var T = new userTypeSupport ();
    em.registerType ( T.in() );

    // create Topic
    em.createTopic ( topic_name );

    // create Publisher
    em.createPublisher ();

    // create dataWriter
    em.createWriter ( false );
    DataWriter_var dwriter = em.getWriter ();
    Writer = userDataWriter::_narrow ( dwriter.in() );

    //create Subscriber
    em.createSubscriber ();

    // create DataReader
    em.createReader ();
    DataReader_var dreader = em.getReader ();
    Reader = userDataReader::_narrow( dreader.in () );
    checkHandle( Reader.in (), "MsgDataReader::_narrow" );
  }
  ~user_data ()
  {
    // Remove the DataWriters.
    em.deleteWriter ();

    // Remove the DataReaders
    em.deleteReader ();

    // Remove the Publisher.
    em.deletePublisher ();

    // Remove the Subscriber.
    em.deleteSubscriber ();

    // Remove the Topics.
    em.deleteTopic ();

    // Remove Participant.
    em.deleteParticipant ();
  }
};
///////////////////////////////////////////////////////////////////////////////
bool exit_flag = false;

void ctrlc ( int )
{
   exit_flag = true;
}
///////////////////////////////////////////////////////////////////////////////

// create the uuid for this user, this session
long long int myUUID;
int seconds = 0;

// instantiate classes
//  the argument is the topic name, or the identifier the data
//  is known by in the DDS middleware.  these must match for
//  everyone on the network. Translation: If you change the topic
//  names, you can communicate with yourself but no one else.

chatroom_data chatRoom ( (char*) "chatroom" );
user_data User ( (char*) "user" );
message_data Message ( (char*) "msg" );
//===================================

/*
void gui()
{

    Fl_Window *dialog;
    Fl_Input *name ;
    Fl_Secret_Input *password;
    Fl_Button *button1;
    Fl_Button *button2;
    Fl_Button *button3;

    dialog = new Fl_Window(1300,900,"SuperChat");
    dialog->color(FL_WHITE);
    name = new Fl_Input(600,300,250,50,"Username:");
    name->align(FL_ALIGN_LEFT);


    password = new Fl_Secret_Input(600,400,250,50,"Password:");
    password->align(FL_ALIGN_LEFT);

    button1 = new Fl_Button(560,500,300,60,"Log in");

    button2 = new Fl_Button(640,620,140,40,"Create New User");

    button3 = new Fl_Button(670,700,70,35,"Exit");

    button1->color(FL_CYAN);
    button3->color(FL_RED);
    dialog->resizable(dialog);
    dialog->end();
    dialog->set_non_modal();
    dialog->show();


    Fl::run();
    return ;


    // will never run
    signal ( SIGINT, ctrlc );
    while(!exit_flag)
    {
        sleep(1);
        string sample;
        std::getline (std::cin,sample);
        int count = 0;
    const bool sendMessage = true;
    if (sendMessage)
    {
        message messageInstance;
        strncpy ( messageInstance.message, sample.c_str(), sizeof ( messageInstance.message ) );
        messageInstance.uuid = myUUID;
        messageInstance.chatroom_idx = 1;
        messageInstance.cksum = 0;
        messageInstance.seqno = count;
        count++;
        Message.send ( messageInstance );
    }
    }
}
//===================================

*/

class ResizerBar : public Fl_Box {
    int orig_h;
    int last_y;
    int min_h;
    void HandleDrag(int diff) {
        Fl_Scroll *grp = (Fl_Scroll*)parent();
        int top = y();
        int bot = y()+h();

        for ( int t=0; t<grp->children(); t++ ) {
            Fl_Widget *w = grp->child(t);
            if ( (w->y()+w->h()) == top ) {
                if ( (w->h()+diff) < min_h ) diff = w->h() - min_h;
                w->resize(w->x(), w->y(), w->w(), w->h()+diff);
                break;
            }
        }
        for ( int t=0; t<grp->children(); t++ ) {
            Fl_Widget *w = grp->child(t);
            if ( w->y() >= bot )
                w->resize(w->x(), w->y()+diff, w->w(), w->h());
        }
        // Change our position last
        resize(x(),y()+diff,w(),h());
        grp->init_sizes();
        grp->redraw();
    }
public:
    ResizerBar(int X,int Y,int W,int H) : Fl_Box(X,Y,W,H,"") {
        orig_h = H;
        last_y = 0;
        min_h = 10;
        align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
        labelfont(FL_COURIER);
        labelsize(H);
        visible_focus(0);
        box(FL_FLAT_BOX);
    }
    void SetMinHeight(int val) { min_h = val; }
    int  GetMinHeight() const { return min_h; }
    int handle(int e) {
        int ret = 0;
        int this_y = Fl::event_y_root();
        switch (e) {
            case FL_FOCUS: ret = 1; break;
            case FL_ENTER: ret = 1; fl_cursor(FL_CURSOR_NS);      break;
            case FL_LEAVE: ret = 1; fl_cursor(FL_CURSOR_DEFAULT); break;
            case FL_PUSH:  ret = 1; last_y = this_y;              break;
            case FL_DRAG:
                HandleDrag(this_y-last_y);
                last_y = this_y;
                ret = 1;
                break;
            default: break;
        }
        return(Fl_Box::handle(e) | ret);
    }
    void resize(int X,int Y,int W,int H) {
        Fl_Box::resize(X,Y,W,orig_h);
    }
};

Fl_Window *dialog;
Fl_Input *Textbox ;
Fl_Button *exit1;
Fl_Button *send1;
Fl_Scroll *scr;
Fl_Multiline_Output *o;
string mess;
string u_name;

void gui()
{


    dialog = new Fl_Window(1200,710,"SuperChat");
    //dialog->color(FL_WHITE);

    Textbox = new Fl_Input (20,630,500,50,"");
    exit1 = new Fl_Button(650,640,70,30,"Exit");
    //exit1->color(FL_RED);
    send1 = new Fl_Button(550,640,70,30,"Send");
    //button2->color(FL_GREEN);
    send1->callback((Fl_Callback *)send_cb, 0);
    exit1->callback((Fl_Callback *)exit_cb, 0);
    scr= new Fl_Scroll(0,0,1200,600);
    dialog->begin();
    scr->begin();
    int resize_h = 5;
    o = new Fl_Multiline_Output(0,(resize_h),1200,1000000000);
    new ResizerBar(0,o->y()+o->h(),200,200);
    scr->end();
    dialog->end();
    dialog->resizable(scr);
    dialog->show();

    Fl::run();
    return;

    // will never run
     signal ( SIGINT, ctrlc );
//    while(!exit_flag)
//    {
//        sleep(1);
//        string sample;
//        std::getline (std::cin,sample);
//        int count = 0;
//    const bool sendMessage = true;
//    if (sendMessage)
//    {
//        message messageInstance;
//        strncpy ( messageInstance.message, sample.c_str(), sizeof ( messageInstance.message ) );
//        messageInstance.uuid = myUUID;
//        messageInstance.chatroom_idx = 1;
//        messageInstance.cksum = 0;
//        messageInstance.seqno = count;
//        count++;
//        Message.send ( messageInstance );
//    }
//    }
}

void send_cb(Fl_Widget* w, void* p)
{
    int count = 0;

    mess = Textbox->value();

    //string sample = Textbox->value();
    Textbox->value("");
    Textbox->clear_output();
    const bool sendMessage = true;
    if (sendMessage)
    {
        message messageInstance;
        strncpy ( messageInstance.message, mess.c_str(), sizeof ( messageInstance.message ) );
        messageInstance.uuid = myUUID;
        messageInstance.chatroom_idx = 1;
        messageInstance.cksum = 0;
        messageInstance.seqno = count;
        count++;
        Message.send ( messageInstance );
        Textbox->redraw();
    }
}

void exit_cb(Fl_Widget* w, void* p)
{
    signal ( SIGINT, ctrlc );
    exit_flag = true;
    dialog->hide();
}
void main_instance()
{
    // set up ctrl-c handler
    signal ( SIGINT, ctrlc );



    //====================================
//    cout << "Enter Username: ";
    string u_name = "Kashif";
//    cin >> u_name;

    //====================================

    // set up some variables



    //o->value("Message shown here");
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << "My UUID is " << uuid << std::endl;
    // lets go old school, and copy it over
    memcpy ( &myUUID, &uuid, sizeof (myUUID) );
    string val;
    // the main loop
    while (!exit_flag)
    {

        // this loop will run forever (or until ^c) and will publish each of
        // records.
        // it will also receive each of the records, if they are out there.
        // Note that things you publish, you will also receive


        // first is chatroom
        if (0 && sendChatroom)
        {
            if (seconds%60 == 0)
            {
                // once a minute change the chatroom name
                chatroom messageInstance;
                messageInstance.chatroom_idx = 1;
                if ( seconds%120 )
                {
                    strncpy ( messageInstance.chatroom_name, "The pleasures", sizeof ( messageInstance.chatroom_name ) );
                }
                else
                {
                    strncpy ( messageInstance.chatroom_name, "The !pleasures", sizeof ( messageInstance.chatroom_name ) );
                }
                chatRoom.send ( messageInstance );
            }
        }

        // user topic
        if (0 && sendUser)
        {
            user messageInstance;
            messageInstance.uuid = myUUID;

            // note the same name with different uuid's is something
            // you have to deal with when printing who is online and
            // where a message is from.

            if ( validate_nick ( u_name.c_str() ) )
            {
                strncpy ( messageInstance.nick, u_name.c_str(), sizeof ( messageInstance.nick ) );
            }

            messageInstance.chatroom_idx = 1;
            if (seconds%2 == 0)
            {
                // 2.0 is less than 2.5, so this is still compliant
                User.send ( messageInstance );
            }
        }

        // message topic
        int count = 0;
        const bool sendMessage = true;
        if (0 && sendMessage)
        {
            message messageInstance;
            if (seconds%15 == 0)
            {
                if ( seconds%30 == 0 )
                {
                    strncpy ( messageInstance.message, "This is the A message.", sizeof ( messageInstance.message ) );
                }
                else
                {
                    strncpy ( messageInstance.message, "This is the B message.", sizeof ( messageInstance.message ) );
                }
                messageInstance.uuid = myUUID;
                messageInstance.chatroom_idx = 1;
                messageInstance.cksum = 0;

                messageInstance.seqno = count;
                count++;
                Message.send ( messageInstance );
            }
        }

        // handle any input coming in
        if (recvChatroom)
        {
            // note the scope of 'List'.
            // if nothing is recv'd, then the vector is empty
            chatroom_list_t  List;
            chatRoom.recv ( &List );
            for (unsigned int i=0; i<List.size ();i++)
            {
                std::cout << "recieved new chatroom name " << List[i].chatroom_name <<
                " chatroom index " << List[i].chatroom_idx << std::endl;
                 Fl::awake ();
            }
        }

        if (recvUser)
        {
            user_list_t  List;
            User.recv ( &List );
            for (unsigned int i=0; i<List.size ();i++)
            {
                std::cout << "recieved user " << std::hex << List[i].uuid
                << std::dec << "  " << List[i].nick
                << " chatroom index " << List[i].chatroom_idx << std::endl;
                 Fl::awake ();
            }
        }

        if (recvMsg)
        {
            message_list_t  List;
            Message.recv ( &List );
            for (unsigned int i=0; i<List.size ();i++)
            {
                std::cout << "recieved user " << List[i].message <<
                " chatroom index " << List[i].chatroom_idx <<
                " sequence # " << List[i].seqno << std::endl;
                val += "recieved user UUID [" + ::to_string(List[i].uuid) + "] :" + string(List[i].message) + " chatroom index(" + ::to_string((List[i].chatroom_idx)) + ")"+ " sequence # " + ::to_string(List[i].seqno) + "\n\n";
               Fl::lock ();
               o->value(val.c_str());
                o->redraw();
                dialog->redraw ();
                Fl::awake ();
                Fl::unlock ();

            }
        }
        Fl::awake ();
        seconds++;
        sleep (1);
    }
    std::cout << "normal exit" << '\n';

}

//===================================
int main()
{
    signal ( SIGINT, ctrlc );
    std::thread first(&main_instance);
    std::thread second(&gui);
   // first.join();
    second.join();
    first.join();

    std::cout << "normal exit path" << '\n';
    //if(exit_flag)
    //return Fl::run();
}
















