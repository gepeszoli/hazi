#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gw = new GameWindow();
    wc = new WaitClientDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gw;
}
// Host server
void MainWindow::on_pushButton_2_clicked()
{
    sockaddr_in serverAddress, clientAddress;	// serverAddress: address to accept connections, clientAddress: address of client
    int rV, socketFD = 0;
    // create stream socket
    socketFD =  socket( AF_INET, SOCK_STREAM, 0);
    CheckError( socketFD, "socket" );
    memset( (void*)&serverAddress, 0, sizeof(serverAddress) );	// clear address
    serverAddress.sin_family = AF_INET;	// set address family
    in_addr_t ina = INADDR_ANY;
    memcpy( &serverAddress.sin_addr, &ina, sizeof(ina));
    serverAddress.sin_port = htons(8888);	// set port number
    // bind socket to address
    rV = bind( socketFD, (struct sockaddr *) &serverAddress, sizeof(sockaddr_in) );
    CheckError( rV, "InitalizeCommandSocket:bind" );
    listen( socketFD, 5 );
    int c = sizeof(struct sockaddr_in);
    int clientSocket = accept( socketFD, (sockaddr*)&clientAddress,  (socklen_t*)&c ) ;
    CheckError( clientSocket, "Accept" );
    this->hide();
    wc->show();
    wc->update();
    wc->hide();
    gw->show();
}
// Connect to server
void MainWindow::on_pushButton_3_clicked()
{
    using namespace std;
    int socketFD, portno, rV;
    sockaddr_in serverAddress;
    hostent *server;
    char buffer[256];
    portno = 8888;
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    CheckError( socketFD, "socket" );
    server = gethostbyname("localhost");
    if (server == NULL) {
        std::cerr << "ERROR, no such host\n";
        exit(0);
    }
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serverAddress.sin_addr.s_addr,
         server->h_length);
    serverAddress.sin_port = htons(portno);
    rV = ::connect(socketFD,(struct sockaddr *) &serverAddress,sizeof(serverAddress));
    CheckError(rV, "Connecting");
    cout << "Successfull connection";
    gw->show();
}
