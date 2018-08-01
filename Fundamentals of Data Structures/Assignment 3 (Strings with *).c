#include<stdio.h>
#include<stdlib.h>

char * readString();
int stringLength(char *string);
void stringCopy(char *string1, char *string2);
void stringReverse(char *string);
int stringPalindrome(char *string);
void stringConcatenate(char *string1, char *string2);

int main()
{
	char *stringA, *stringB, *stringC;
	int choice, length, check;
	char repeat='y';
	
	stringA=readString();
	stringB=readString();
	
	while(repeat=='y' || repeat=='Y')
	{
		printf("\n1. Length\n2. Palindrome\n3. Comparison\n4. Copy\n5. Reverse\n6. Substring\n7. Concatenate");
		printf("\nSelect the operation: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					length=stringLength(stringA);
					printf("Length of the string is %d", length);
					break;
				}
			case 2:
				{
					check=stringPalindrome(stringA);
					if(check==0)
					{
						printf("String is not a palindrome!");
					}
					else
					{
						printf("String is a palindrome!");
					}
					break;
				}
			case 3:
				{
					/*printf("\nEnter another string to compare: ");
					scanf("%s", stringB);
					check=stringCompare(stringA, stringB);
					if(check==0)
					{
						printf("Strings are same!");
					}
					else if(check<0)
					{
						printf("String 2 is greater than string 1!");
					}
					else
					{
						printf("String 1 is greater than string 2!");
					}*/
					break;
				}
			case 4:
				{
					stringCopy(stringB, stringA);
					printf("%s is copied in another string!", stringB);
					break;
				}
			case 5:
				{
					stringReverse(stringA);
					break;
				}
			case 6:
				{
					/*printf("\nEnter another string to search: ");
					scanf("%s", stringB);
					if(stringLength(stringB)<stringLength(stringA))
					{
						check=substring(stringA, stringB);
						if(check==0)
						{
							printf("Entered string does not occur in %s", stringA);
						}
						else
						{
							printf("Entered string occurs %d times in %s", check, stringA);
						}
					}
					else
					{
						printf("Invalid string!");
					}*/
					break;
				}
			case 7:
				{
					//stringB=readString();
					stringC=(char *) malloc(sizeof(char)*(stringLength(stringA)+stringLength(stringB))+1);
					stringCopy(stringC, stringA);
					stringConcatenate(stringC, stringB);
					break;
				}
			default:
				{
					printf("Incorrect selection! Enter a number between 1-6\n");
					break;
				}
		}
		
		printf("\nDo you want to perform another operation? (y/n)");
		scanf(" %c", &repeat);
	}
	
	return 0;
}

char * readString()
{
	int length=0;
	char temp[50], *string;
	printf("Enter a string: ");
	scanf(" %[^\n]", temp);
	string=(char *) malloc((sizeof(char)*stringLength(temp)+1));
	stringCopy(string, temp);
	return string;
}

int stringLength(char *string)
{
	int length=0;
	while(string[length]!='\0')
	{
		length++;
	}
	return length;
}

void stringCopy(char *string1, char *string2)
{
    int i=0;
    while(string2[i]!='\0')
    {
        string1[i]=string2[i];
        i++;
    }
    string1[i]='\0';
}

void stringReverse(char *string)
{
	int i, j;
	char reverse[50];
	for(i=0, j=(stringLength(string) -1); i<stringLength(string), j>=0; i++, j--)
	{
		reverse[i]=string[j];
	}
	printf("The reversed string is %s", reverse);
}

int stringPalindrome(char *string)
{
    int length, i, j;
    length=stringLength(string);
    if(length%2==0)
    {
        i=(length/2)-1;
        j=i+1;
    }
    else
    {
        i=((length-1)/2)-1;
        j=i+2;
    }
    while(j<length)
    {
    	if(string[i]==string[j])
        {
            i--;
            j++;
        }
        else
        {
            return 0;
            break;
        }
    }
    return 1; 
}

void stringConcatenate(char *string1, char *string2)
{
	int i, j, length1, length2;
	length1=stringLength(string1);
	length2=stringLength(string2);
	i=length1+1;
	while(string2[j]!='\0')
	{
		string1[i]=string2[j];
		i++;
		j++;
	}
	//for(i=length1+1, j=0; string2[j]!='\0'; i++, j++)
	string1[i]='\0';
}
