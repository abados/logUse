
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)


void log(char message[100])
{
	time_t t;
	time(&t);
	struct tm* timeInfo;
	timeInfo = localtime(&t);
	char strTime[1000];
	sprintf(strTime, "%d %d %d\n", timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday);


	FILE* f = fopen("myProg.log", "a");
	
	strcat(strTime, message);
	printf("%s", strTime);
	while (fputs(strTime, f) != NULL)
	{
		
	}
	
	fclose(f);

}

void LogError(char* message) {

	char s[1000] = "Error! ";
	strcat(s, message);
	strcpy(message, s);
	log(message);

}

void LogEvent(char message[100]) {
	char s[1000] = "EVENT - ";
	strcat(s, message);
	strcpy(message, s);
	log(message);
}

int askForNum()
{
	int x;
	printf("please choose a number:");
	scanf("%d", &x);
	return x;
}

int main()
{
	
	
	FILE* f = fopen("myProg.log", "a");
	char strchosenNum[1000];

	char strWriteToLog[1000]="program start\n";
	LogEvent(strWriteToLog);

	strcpy(strWriteToLog , "the user is chosing number\n");
	LogEvent(strWriteToLog);
	sprintf(strchosenNum, "%d\n", askForNum());
	log(strchosenNum);
	
	fclose(f);

	FILE* f2 = fopen("myProg2.log", "a");
	if (!f2)
	{
		strcpy(strWriteToLog, "The file F2 couldent be open");
		LogError(strWriteToLog);

	}
	else
	{
		strcpy(strWriteToLog, "The file F2 opened succsesfully - GOOD JOB!\n");
	LogEvent(strWriteToLog);
	char strResult[1000]="";
	for (int i = 1; i <= atoi(strchosenNum); i++)
	{
		sprintf(strResult, "%s %d ", strResult, i);
	}
	printf("%s", strResult);
	strcpy(strWriteToLog, "The file F2 task is runnig succesfully - GOOD JOB!\n");
	fputs(strResult, f2);
	LogEvent(strWriteToLog);

	fclose(f2);
}
	strcpy(strWriteToLog, "The program is Finished\n");
	LogEvent(strWriteToLog);
	
    return 0;
}
