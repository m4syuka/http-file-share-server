#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <fcntl.h>

//другое 
extern const int MAX_SIZE_BUFF;
extern char addressBuffer[INET_ADDRSTRLEN];

//для открытия папки
DIR *dir;
struct dirent *de;
int totalFileInDir;

//Открытие файла для чтения
FILE *fp;
long int fileSize;

//выбор файла или папки 
//если это папка, то = 0, если файл = 1, аплоад на сервер = 2 
int selectDorF;

//функа генерации html
void GenerationHtml(const char* dirInput);

//функа парсинга запроса и генерации ответа
int ParseHtml(char *buffClientRequest,char *serv_response,const char *dirInput,const char* fileInput);

//функа для вычисления размера файла 
void GetFileSize(FILE *fp, char *chrFileSize);

//функа отправки данных 
void SendData(int sock_client,const char *serv_response);
