#include <ctype.h>

#include <string.h>

#include <stdio.h>

#define Max 20

int isvalidpan(char str[])

{

    int i;

    if(strlen(str)==10)

    {

        for(i=0;i<=4;i++)

        {

            if(! isalpha(str[i]) )

                return 0;

        }

        for(i=5;i<=8;i++)

        {

            if(! isdigit(str[i]) )

                return 0;

        }

        if(! isalpha(str[9]) )

            return 0;

    return 1;

    }

    return 0;

}



int isvalidaadhaar(char str[])

{

    int i;

    if(strlen(str)==12)

    {

        for(i=0;i<=11;i++)

        {

            if(! isdigit(str[i]) )

                return 0;

        }

    return 1;

    }

    return 0;

}



int isvalidbirth(char str[])

{

    int i;

    if(strlen(str)==10)

    {

        for(i=0;i<=1;i++)

        {

            if(! isdigit(str[i]) )

            return 0;

        }

        if(! str[2]=='/' )

           return 0;

        for(i=3;i<=4;i++)

        {

            if(! isdigit(str[i]) )

            return 0;

        }

        if(! str[5]=='/' )

            return 0;

        for(i=6;i<=9;i++)

        {

            if(! isdigit(str[i]) )

            return 0;

        }

    return 1;

    }

    return 0;

}
