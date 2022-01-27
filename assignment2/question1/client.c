#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//Create a Socket for server communication
short SocketCreate(void)
{
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}
//try to connect with server
int SocketConnect(int hSocket)
{
    int iRetval=-1;
    int ServerPort = 90190;
    struct sockaddr_in remote= {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(hSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
    return iRetval;
}
// Send the data to the server and set the timeout of 20 seconds
int SocketSend(int hSocket,char* Rqst,short lenRqst)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;
    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;

}
//Generate Data Frame
char[] FrameGenerate(){
    char[] frame = new char[100];
    int frame_number = 10;
    int i=0;
    for(frame_number > 0){
        int random_frame_byte = rand() % 5;
        char[i] = random_frame_byte+'0';
        i++;
        for(int j = 0; i < random_frame_byte-1; j++){
            frame[i] = rand() % 8 + '0';
            i++;
        }
        frame_number--;
    }
    frame[i] = '\0';
    return frame;
}
//Check the validity of data frame by byte count method
bool CheckFrameValidity(char* bytes){
    length = sizeof(bytes)/sizeof(bytes[0]);
    int i = 0;
    for(i<length){
        int byte_count = atoi(bytes[i]);
        for(int j = i++; j < i+byte_count-1; j++){}
        i = byte_count;
    }
    if(bytes[i] == '\0'){
        return true;
    }
    printf("Invalid Framed Data\n");
    return false;
}

//receive the data from the server
int SocketReceive(int hSocket,char* Rsp,short RvcSize)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;
    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO,(char *)&tv,sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    if(CheckFrameValidity(Rsp)){
         printf("Server Response %s\n",Rsp);
         return shortRetval;
    }
    
    return -1; 
}
//main driver program
int main(int argc, char *argv[])
{
    int hSocket, read_size;
    struct sockaddr_in server;
    char SendToServer[100] = {0};
    char ServerReply[200] = {0};
    //Create socket
    hSocket = SocketCreate();
    if(hSocket == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket is created\n");
    //Connect to remote server
    if (SocketConnect(hSocket) < 0)
    {
        perror("connect failed.\n");
        return 1;
    }
    printf("Sucessfully conected with server\n");
    SendToServer = FrameGenerate();
    //Send data to the server
    SocketSend(hSocket, SendToServer, strlen(SendToServer));
    //Received the data from the server
    read_size = SocketReceive(hSocket, ServerReply, 200);
    if(read_size == -1)
    {
        printf("Invalid response from server\n");
        return 1;
    }    
    close(hSocket);
    shutdown(hSocket,0);
    shutdown(hSocket,1);
    shutdown(hSocket,2);
    return 0;
}