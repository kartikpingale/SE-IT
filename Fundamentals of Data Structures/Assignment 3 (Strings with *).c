#include<stdio.h>

int stringLength(char *string);
void stringReverse(char *string, char *reverse);
void stringCopy(char *string1, char *string2);
int stringPalindrome(char *string);
int stringCompare(char *string1, char *string2);
int substring(char *string1, char *string2);

int main()
{
	char stringA[100], stringB[100];
	int choice, length, check;
	char repeat='y';
	
	printf("Enter a string: ");
	scanf("%[^\n]", stringA);
	
	while(repeat=='y' || repeat=='Y')
	{
		printf("\n1. Length\n2. Palindrome\n3. Comparison\n4. Copy\n5. Reverse\n6. Substring");
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
					printf("\nEnter another string to compare: ");
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
					}
					break;
				}
			case 4:
				{
					stringCopy(stringA, stringB);
					break;
				}
			case 5:
				{
					stringReverse(stringA, stringB);
					break;
				}
			case 6:
				{
					printf("\nEnter another string to search: ");
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
					}
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

int stringLength(char *string)
{
	int length=0;
	while(string[length]!='\0')
	{
		length++;
	}
	return length;
}

void stringReverse(char *string, char *reverse)
{
	int i, j;
	for(i=0, j=(stringLength(string) -1); i<stringLength(string), j>=0; i++, j--)
	{
		reverse[i]=string[j];
	}
	printf("The reversed string is %s", reverse);
}

void stringCopy(char *string1, char *string2)
{
    int i=0;
    while(string1[i]!='\0')
    {
        string2[i]=string1[i];
        i++;
    }
    printf("Entered string is copied into another string!\nThe copied string is %s", string2);
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

int stringCompare(char *string1, char *string2)
{
	int i=0;
	while(string1[i]!='\0' || string2[i]!='\0')
	{
		if(string1[i]-string2[i]==0)
		{
			i++;
		}
		else
		{
			return string1[i]-string2[i];
		}
	}
	return 0;
}

int substring(char *string1, char *string2)
{
	int i, j, flag, occurrence=0;
	for(i=0; i<(stringLength(string1)-stringLength(string2)); i++)
	{
		for(j=i; j<(i+stringLength(string2)); j++)
		{
			flag=1;
			if(string1[j]!=string2[j-i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			occurrence++;
		}
	}
	return occurrence;
}
