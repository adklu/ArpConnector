
//ArpConnector: Copyright (c) 2016 A. Klumpp


// *  This program is free software; you can redistribute it and/or modify
// *  it under the terms of the GNU General Public License as published by
// *  the Free Software Foundation; either version 2 of the License, or
// *  (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// *  GNU General Public License for more details.
// *
// *  You should have received a copy of the GNU General Public License
// *  along with this program; if not, write to the Free Software
// *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA



// Add ArpConnector to the autostart programs (e.g. from usr/local/bin) in order to get a "screen free" qmidiarp linux (e.g. raspberry pi) box (tested with qmidiarp and midi controller; set the clock to midi input to start and stop qmidiarp via midi controller).
// Please restart ArpConnector after saving changes (e.g. changing the path of the qmidiarp file).



//install libasound2 and libasound2-dev

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "arecordmidi.c"
#include <QDebug>
#include <QProcess>
#include <QMessageBox>
#include <unistd.h>

#include <QDateTime>



#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>
#include <sys/poll.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>
#include <sys/poll.h>
#include <alsa/include/asoundlib.h>
//#include <alsa/include/aconfig.h>
#include <alsa/include/config.h.in>
#include <alsa/include/version.h>

//


#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int mrid;
int mrport;


QProcess process1;
QProcess process2;
QProcess process3;
QProcess process4;
QProcess process5;


static int queue;


QList<QString> nameAr;
QList<QString> clientAr;
QList<QString> portAr;
QList<QString> fullAr;

QList<QString> nameArIn;
QList<QString> clientArIn;
QList<QString> portArIn;
QList<QString> fullArIn;






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //

    QFile hfile(".pathhfile.txt");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd()) {
        QString hostr = in.readLine();
        //qDebug() << hostr;
        if(~(hostr.isEmpty())){
        ui->lineEditPath->setText(hostr);}
                }


    QString pathhost = ui->lineEditPath->text();
    qDebug() << pathhost;

    if(pathhost.trimmed().isEmpty())
        {

    ui->statusBar->showMessage("qmidiarp file path missing");

    //while (n<1)                {
    QMessageBox msgBox;
    msgBox.setText("Please enter the qmidiarp file path.");
    msgBox.exec();
            //n++;                }

           }

    else
        {



          qDebug() << "before sleep";

          QString ccommand = "gnome-terminal -x bash -c \"qmidiarp " + pathhost + " -a";

         qDebug() <<  ccommand;

          process5.start(ccommand);




wait();

    }

}

void MainWindow::wait()
{

 //usleep(5000000);

    for(int i = 0; i <= 5; i++)
       {
           qDebug() << i;


           sleep(1);
       }

     qDebug() << "after sleep";
output();
}

void MainWindow::wait1()
{


    for(int i = 0; i <= 1; i++)
       {
           qDebug() << i;


           sleep(1);
       }

     qDebug() << "after sleep";

}


void MainWindow::output()
{



        //





#define perm_ok(pinfo,bits) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))
snd_seq_t *seq;
snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
//

    mrid = snd_seq_client_id(seq);
    //qDebug() <<  mrid;

    mrport = snd_seq_set_client_name(seq, "AlsaConnector");
    //qDebug() <<  mrport;

    //
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    //



        snd_seq_port_info_alloca(&pinfo);


        snd_seq_port_info_set_capability(pinfo,
                         SND_SEQ_PORT_CAP_WRITE |
                         SND_SEQ_PORT_CAP_SUBS_WRITE);
        snd_seq_port_info_set_type(pinfo,
                       SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                       SND_SEQ_PORT_TYPE_APPLICATION);
        snd_seq_port_info_set_midi_channels(pinfo, 16);


        snd_seq_port_info_set_timestamping(pinfo, 1);
        snd_seq_port_info_set_timestamp_queue(pinfo, queue);




//



    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    while (snd_seq_query_next_client(seq, cinfo) >= 0)

    {
            snd_seq_port_info_set_client(pinfo, snd_seq_client_info_get_client(cinfo));
            snd_seq_port_info_set_port(pinfo, -1);

            int seldd = 0;
             int iseldd = 0;

            while (snd_seq_query_next_port(seq, pinfo) >= 0)


                //output


                if (    perm_ok
                                       (pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ))
                                       //(pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE))
                                           {
                                               QString pname = snd_seq_port_info_get_name(pinfo);
                                              //qDebug() << pname;
                                               nameAr.append(pname);
                                               int icnum = snd_seq_client_info_get_client(cinfo);
                                               QString scnum = QString::number(icnum);
                                              // qDebug() << scnum;
                                               clientAr.append(scnum);
                                               //
                                               const char* fullname = snd_seq_client_info_get_name(cinfo);
                                              // qDebug() << "fullname";
                                                   // qDebug() << fullname;
                                                    fullAr.append(fullname + pname);
                                               //
                                               int ipnum = snd_seq_port_info_get_port(pinfo);
                                               QString spnum = QString::number(ipnum);
                                             // qDebug() << spnum;
                                               portAr.append(spnum);
                                              seldd++;
                                           }






     }


    //ui->comboBoxKeyOut->addItems(fullAr);
    loadselectioncomboBoxKeyOut();
    loadselectioncomboBoxArpOut();
    loadselectioncomboBoxClockOut();


    // ui->comboBoxArpOut->addItems(fullAr);
    //  ui->comboBoxClockOut->addItems(fullAr);
   // old:ui->comboBox2->addItems(nameArIn);

    input();
}





void MainWindow::input()

{

qDebug() << "input function";

#define perm_ok(pinfo,bits) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))
snd_seq_t *seq;
snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
//

    mrid = snd_seq_client_id(seq);
    //qDebug() <<  mrid;

    mrport = snd_seq_set_client_name(seq, "AlsaConnector");
    //qDebug() <<  mrport;

    //
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    //



        snd_seq_port_info_alloca(&pinfo);


        snd_seq_port_info_set_capability(pinfo,
                         SND_SEQ_PORT_CAP_WRITE |
                         SND_SEQ_PORT_CAP_SUBS_WRITE);
        snd_seq_port_info_set_type(pinfo,
                       SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                       SND_SEQ_PORT_TYPE_APPLICATION);
        snd_seq_port_info_set_midi_channels(pinfo, 16);


        snd_seq_port_info_set_timestamping(pinfo, 1);
        snd_seq_port_info_set_timestamp_queue(pinfo, queue);


//


//


snd_seq_client_info_alloca(&cinfo);
snd_seq_port_info_alloca(&pinfo);
snd_seq_client_info_set_client(cinfo, -1);
while (snd_seq_query_next_client(seq, cinfo) >= 0)

{
        snd_seq_port_info_set_client(pinfo, snd_seq_client_info_get_client(cinfo));
        snd_seq_port_info_set_port(pinfo, -1);

        int seldd = 0;
         int iseldd = 0;

        while (snd_seq_query_next_port(seq, pinfo) >= 0)



            //input (write)
            if (    perm_ok
                    //(pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ))
                    (pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE))
                        {
                            QString ipname = snd_seq_port_info_get_name(pinfo);
                            qDebug() << "ipname";
                           qDebug() << ipname;
                            nameArIn.append(ipname);
                            int iicnum = snd_seq_client_info_get_client(cinfo);
                            QString iscnum = QString::number(iicnum);
                            qDebug() << iscnum;
                            clientArIn.append(iscnum);
                            //
                            const char* ifullname = snd_seq_client_info_get_name(cinfo);
                            //qDebug() << "ifullname";
                                 qDebug() << ifullname;
                                 fullArIn.append(ifullname + ipname);
                            //
                            int iipnum = snd_seq_port_info_get_port(pinfo);
                            QString ispnum = QString::number(iipnum);
                          // qDebug() << ispnum;
                            portArIn.append(ispnum);

                            qDebug() << "iseldd";
                            qDebug() << iseldd;


                            //WIP


                            QString KeyboardName = "nanoKEY2";

                            if (ipname.contains(KeyboardName))
                               // if (String.contains(searchString, Qt::CaseSensitive))
                            {
                            qDebug() << "this ipname is " + ipname + " and iscnum is " + iscnum;


                              //s = ui->lineEdit->text();



                             }


                            //iseldd++;

                        }

            //input end





 }

loadselectioncomboBoxArpIn();
loadselectioncomboSynthIn();
loadselectioncomboBoxClockIn();


autoconnect();

//ui->comboBoxClients->addItems(nameAr);
 //ui->comboBoxArpIn->addItems(fullArIn);
 //ui->comboSynthIn->addItems(fullArIn);
 //ui->comboBoxClockIn->addItems(fullArIn);


}


//keep selection of combobox
//
void MainWindow::loadselectioncomboBoxKeyOut()

{
           ui->comboBoxKeyOut->clear();
          //colAr.append("-");
          ui->comboBoxKeyOut->addItems(fullAr);
           ui->comboBoxKeyOut->setCurrentIndex(0);

          QFile hfile(".comboBoxKeyOut");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxKeyOut->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxKeyOut->findText(keepselectID);
                  ui->comboBoxKeyOut->setCurrentIndex(indexID);
                }

           }

}

//

 void MainWindow::loadselectioncomboBoxArpOut()

 {
            ui->comboBoxArpOut->clear();
           //colAr.append("-");
           ui->comboBoxArpOut->addItems(fullAr);
            ui->comboBoxArpOut->setCurrentIndex(0);

           QFile hfile(".comboBoxArpOut");
           if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
               return;
           QTextStream in(&hfile);
           while (!in.atEnd())

            {              QString keepselectID = in.readLine();
               //qDebug() << keepselectID;


               if(keepselectID=="")
                 {
               ui->comboBoxArpOut->setCurrentIndex(0);
                  }
               else
                  {
                   int indexID = ui->comboBoxArpOut->findText(keepselectID);
                   ui->comboBoxArpOut->setCurrentIndex(indexID);
                 }

            }

 }


//

void MainWindow::loadselectioncomboBoxClockOut()
{
           ui->comboBoxClockOut->clear();
          //colAr.append("-");
          ui->comboBoxClockOut->addItems(fullAr);
           ui->comboBoxClockOut->setCurrentIndex(0);

          QFile hfile(".comboBoxClockOut");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxClockOut->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxClockOut->findText(keepselectID);
                  ui->comboBoxClockOut->setCurrentIndex(indexID);
                }

           }

}


//

void MainWindow::loadselectioncomboBoxArpIn()
{
           ui->comboBoxArpIn->clear();
          //colAr.append("-");
          ui->comboBoxArpIn->addItems(fullArIn);
           ui->comboBoxArpIn->setCurrentIndex(0);

          QFile hfile(".comboBoxArpIn");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxArpIn->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxArpIn->findText(keepselectID);
                  ui->comboBoxArpIn->setCurrentIndex(indexID);
                }

           }

}

//

void MainWindow::loadselectioncomboSynthIn()
{
           ui->comboSynthIn->clear();
          //colAr.append("-");
          ui->comboSynthIn->addItems(fullArIn);
           ui->comboSynthIn->setCurrentIndex(0);

          QFile hfile(".comboSynthIn");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboSynthIn->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboSynthIn->findText(keepselectID);
                  ui->comboSynthIn->setCurrentIndex(indexID);
                }

           }

}

//

void MainWindow::loadselectioncomboBoxClockIn()
{
           ui->comboBoxClockIn->clear();
          //colAr.append("-");
          ui->comboBoxClockIn->addItems(fullArIn);
           ui->comboBoxClockIn->setCurrentIndex(0);

          QFile hfile(".comboBoxClockIn");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxClockIn->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxClockIn->findText(keepselectID);
                  ui->comboBoxClockIn->setCurrentIndex(indexID);
                }

           }

}
//if autoconnect is active

void MainWindow::autoconnect()

{

    QFile hfile(".autoconnect");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd())

     {              QString trueorfalse = in.readLine();
        //qDebug() << keepselectID;


        if(trueorfalse=="")
          {
            ui->labelStatus->setText("Autoconnect: OFF");

           }
          if(trueorfalse=="true")
           {
            ui->labelStatus->setText("Autoconnect: ON");
            slotrec();
          }

     }




}






//


void MainWindow::slotrec()

{
//connecting midi





      int getmididev = ui->comboBoxKeyOut->currentIndex();

            //qDebug() << getmididev;


      if (getmididev<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else
      {

      QString getclient =  clientAr[getmididev];
      int igetclient = getclient.toInt();
      qDebug() << igetclient;

      QString getport =  portAr[getmididev];
      int igetport = getport.toInt();
      qDebug() << igetport;


      //


      int getmididev2 = ui->comboBoxArpIn->currentIndex();
      //qDebug() << getmididev;


      if (getmididev2<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }

      else

        {

      QString getclient2 =  clientArIn[getmididev2];
      int igetclient2 = getclient2.toInt();
      qDebug() << igetclient2;

      QString getport2 =  portArIn[getmididev2];
      int igetport2 = getport2.toInt();
      qDebug() << igetport2;





     //  QString acommand = "gnome-terminal -x bash -c \"arecordmidi -p " + getclient + ":" + getport + " " + filename;

     // aconnect [-options] sender receiver
      //    sender, receiver = client:port pair

    //  aconnect 28:0 32:0


      QString acommand = "gnome-terminal -x bash -c \"aconnect " + getclient + ":" + getport + " " + getclient2 + ":" + getport2;

     qDebug() <<  acommand;

      process1.start(acommand);


      //

      wait1();

      //

      int getmididev3 = ui->comboBoxArpOut->currentIndex();
      //qDebug() << getmididev;

      if (getmididev3<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else

      {

      QString getclient3 =  clientAr[getmididev3];
      int igetclient3 = getclient3.toInt();
      qDebug() << igetclient3;

      QString getport3 =  portAr[getmididev3];
      int igetport3 = getport3.toInt();
      qDebug() << igetport3;


      //


      int getmididev4 = ui->comboSynthIn->currentIndex();
      //qDebug() << getmididev;

      if (getmididev4<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else

      {

      QString getclient4 =  clientArIn[getmididev4];
      int igetclient4 = getclient4.toInt();
      qDebug() << igetclient4;

      QString getport4 =  portArIn[getmididev4];
      int igetport4 = getport4.toInt();
      qDebug() << igetport4;

      QString acommand2 = "gnome-terminal -x bash -c \"aconnect " + getclient3 + ":" + getport3 + " " + getclient4 + ":" + getport4;

     qDebug() <<  acommand2;

      process2.start(acommand2);


      //
 qDebug() <<  "before new sleep";
      wait1();
       qDebug() <<  "after new sleep1";

      //

      int getmididev5 = ui->comboBoxClockOut->currentIndex();
      qDebug() << getmididev5;

      if (getmididev5<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


          else
          {
      QString getclient5 =  clientAr[getmididev5];



      int igetclient5 = getclient5.toInt();
      qDebug() << igetclient5;



      QString getport5 =  portAr[getmididev5];
      int igetport5 = getport5.toInt();
      qDebug() << igetport5;


      //

      int getmididev6 = ui->comboBoxClockIn->currentIndex();
      //qDebug() << getmididev;


      if (getmididev6<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }

      else

      {

      QString getclient6 =  clientArIn[getmididev6];
      int igetclient6 = getclient6.toInt();
      qDebug() << igetclient6;

      QString getport6 =  portArIn[getmididev6];
      int igetport6 = getport6.toInt();
      qDebug() << igetport6;

      QString acommand3 = "gnome-terminal -x bash -c \"aconnect " + getclient5 + ":" + getport5 + " " + getclient6 + ":" + getport6;

     qDebug() <<  acommand3;

      process3.start(acommand3);







 //qDebug() <<  mrid;




 ui->statusBar->showMessage("Connected");


}


}

}
}
}

}
}

void MainWindow::slotstop()

{
    int getmididev = ui->comboBoxKeyOut->currentIndex();
    //qDebug() << getmididev;

    QString getclient =  clientAr[getmididev];
    int igetclient = getclient.toInt();
    qDebug() << igetclient;

    QString getport =  portAr[getmididev];
    int igetport = getport.toInt();
    qDebug() << igetport;


    //


    int getmididev2 = ui->comboBoxArpIn->currentIndex();
    //qDebug() << getmididev;

    QString getclient2 =  clientArIn[getmididev2];
    int igetclient2 = getclient2.toInt();
    qDebug() << igetclient2;

    QString getport2 =  portArIn[getmididev2];
    int igetport2 = getport2.toInt();
    qDebug() << igetport2;




    //

 QString acommand = "gnome-terminal -x bash -c \"aconnect -d " + getclient + ":" + getport + " " + getclient2 + ":" + getport2;

qDebug() <<  acommand;

 process1.start(acommand);

 //
//
 //

 wait1();

 //

 int getmididev3 = ui->comboBoxArpOut->currentIndex();
 //qDebug() << getmididev;

 QString getclient3 =  clientAr[getmididev3];
 int igetclient3 = getclient3.toInt();
 qDebug() << igetclient3;

 QString getport3 =  portAr[getmididev3];
 int igetport3 = getport3.toInt();
 qDebug() << igetport3;


 //


 int getmididev4 = ui->comboSynthIn->currentIndex();
 //qDebug() << getmididev;

 QString getclient4 =  clientArIn[getmididev4];
 int igetclient4 = getclient4.toInt();
 qDebug() << igetclient4;

 QString getport4 =  portArIn[getmididev4];
 int igetport4 = getport4.toInt();
 qDebug() << igetport4;

 QString acommand2 = "gnome-terminal -x bash -c \"aconnect -d " + getclient3 + ":" + getport3 + " " + getclient4 + ":" + getport4;

qDebug() <<  acommand2;

 process2.start(acommand2);


 //
qDebug() <<  "before new sleep";
 wait1();
  qDebug() <<  "after new sleep2";

 //

 int getmididev5 = ui->comboBoxClockOut->currentIndex();
 //qDebug() << getmididev;

 QString getclient5 =  clientAr[getmididev5];
 int igetclient5 = getclient5.toInt();
 qDebug() << igetclient5;

 QString getport5 =  portAr[getmididev5];
 int igetport5 = getport5.toInt();
 qDebug() << igetport5;


 //


 int getmididev6 = ui->comboBoxClockIn->currentIndex();
 //qDebug() << getmididev;

 QString getclient6 =  clientArIn[getmididev6];
 int igetclient6 = getclient6.toInt();
 qDebug() << igetclient6;

 QString getport6 =  portArIn[getmididev6];
 int igetport6 = getport6.toInt();
 qDebug() << igetport6;

 QString acommand3 = "gnome-terminal -x bash -c \"aconnect -d " + getclient5 + ":" + getport5 + " " + getclient6 + ":" + getport6;

qDebug() <<  acommand3;

 process3.start(acommand3);





//
 //

 ui->statusBar->showMessage("");

 ui->labelStatus->setText("Autoconnect: OFF");



 //save ID settings
 QString cbID = "";
 //qDebug() << cbID;
 QFile cbIDfile(".autoconnect");
        if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outg(&cbIDfile);
        outg << cbID;

           cbIDfile.close();








      //aconnect -i


//process1.terminate(SIGINT);
//process.close();
}





void MainWindow::on_pushButtonPath_pressed()
{

       QString pathhost = ui->lineEditPath->text();



       if(pathhost.trimmed().isEmpty())
                   {
       QMessageBox msgBox;
       msgBox.setText("Please enter path.");
       msgBox.exec();
                    }


       else
       {

       QFile hfile(".pathhfile.txt");
            if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            QTextStream outh(&hfile);
            outh << pathhost;

        }






}










void MainWindow::on_pushButtonKey_pressed()
{
    qDebug() <<  "keysavebutton works";



    //save ID settings
    QString cbID = ui->comboBoxKeyOut->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboBoxKeyOut");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();





}

void MainWindow::on_pushButtonArpIn_pressed()
{
    qDebug() <<  "pushButtonArpInbutton works";



    //save ID settings
    QString cbID = ui->comboBoxArpIn->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboBoxArpIn");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonArpOut_pressed()
{
    qDebug() <<  "pushButtonArpOutbutton works";



    //save ID settings
    QString cbID = ui->comboBoxArpOut->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboBoxArpOut");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonSynthIn_pressed()
{
    qDebug() <<  "pushButtonSynthInbutton works";



    //save ID settings
    QString cbID = ui->comboSynthIn->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboSynthIn");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonClockOut_pressed()
{
    qDebug() <<  "pushButtonClockOutbutton works";



    //save ID settings
    QString cbID = ui->comboBoxClockOut->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboBoxClockOut");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonClockIn_pressed()
{
    qDebug() <<  "pushButtonClockInbutton works";



    //save ID settings
    QString cbID = ui->comboBoxClockIn->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".comboBoxClockIn");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonAuto_pressed()
{
    qDebug() <<  "pushButtonAuto works";

    ui->labelStatus->setText("Autoconnect active");



    //save ID settings
    QString cbID = "true";
    //qDebug() << cbID;
    QFile cbIDfile(".autoconnect");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}







MainWindow::~MainWindow()
{
    delete ui;
}
