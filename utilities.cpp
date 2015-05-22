#include "utilities.h"
using namespace std;

void CheckError(int returnValue, const char *messageBeginning) {
    char errorMsgBuf[200]; // this array would hold the error string returned by strerror_r
                               // check out: http://www.domaigne.com/blog/computing/pthreads-errors-and-errno/
    stringstream ss; // stringstream used to create exception messages
    if( returnValue < 0)
    {
        strerror_r( returnValue, errorMsgBuf, sizeof( errorMsgBuf ) / sizeof( errorMsgBuf[0] ) ); // get error message
        ss << messageBeginning << ": " << errorMsgBuf << " error code: " << returnValue; // write message to stringstream
        cout << ss.str() << endl;
        throw runtime_error( ss.str() );
    }
    return;
}
int writeToSocket(int fileDescriptor, const char* buffer, unsigned length) //protects against possible interruption of 'write'
{
    int left, written; // left: the number of bytes left to write written: the number of written bytes
    for(left = (int) length; left > 0; )
    {
        written = write(fileDescriptor, buffer, left);
        if(written <= 0)
        {
            if( written < 0 && errno == EINTR )
            {
                written = 0;
            }
            else
            {
                return -1; //signal error
            }
        }
        left -= written;
        buffer += written;
    }
    return length;
}
int readFromSocket(int fileDescriptor, char* buffer, unsigned length) //protects against possible interruption of 'read'
{
    int bytesRead, left;
    left = length;
    while( left > 0 )
    {
        bytesRead = read(fileDescriptor, buffer, left);
        if(bytesRead < 0)
        {
            if( errno == EINTR)
            {
                bytesRead = 0;
            }
            else
            {
                return -1;
            }
        }
        else if(bytesRead == 0)
        {
            break;
        }
        left -= bytesRead;
        buffer += bytesRead;
    }
    return length-left;
}
