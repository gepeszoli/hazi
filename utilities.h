#ifndef UTILITIES_H
#define UTILITIES_H
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <resolv.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <signal.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
void CheckError(int returnValue, const char *messageBeginning);
#endif // UTILITIES_H

