#include<stdio.h>

int stringLength(char string[]);
void stringReverse(char string[], char reverse[]);
void stringCopy(char string1[], char string2[]);
void stringPalindrome(char string[]);

int main()
{
	char stringA[100], stringB[100];
	int choice, length;
	char repeat='y';
	
	printf("Enter a string: ");
	scanf("%s", stringA);
	
	while(repeat=='y' || repeat=='Y')
	{
		printf("\n1. Length\n2. Palindrome\n3. String Comparison\n4. Copy\n5. Reverse\n6. Substring");
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
					stringPalindrome(stringA);
					break;
				}
			case 3:
				{
					
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

int stringLength(char string[])
{
	int i=0, length=0;
	while(string[i]!='\0')
	{
		length++;
		i++;
	}
	return length;
}

void stringReverse(char string[], char reverse[])
{
	int i, j;
	for(i=0, j=(stringLength(string) -1); i<stringLength(string), j>=0; i++, j--)
	{
		reverse[i]=string[j];
	}
	printf("The reversed string is %s", reverse);
}

void stringCopy(char string1[], char string2[])
{
    int i=0;
    while(string1[i]!='\0')
    {
        string2[i]=string1[i];
        i++;
    }
    printf("Entered string is copied into another string!\nThe copied string is %s", string2);
}

void stringPalindrome(char string[])
{
    int length, i, j;
    length=stringLength(string);
    if(length%2==0)
    {
        i=(length/2)-1;
        j=i+1;
        while(j<length)
        {
            if(string[i]==string[j])
            {
                i--;
                j++;
            }
            else
            {
                printf("String is not a palindrome!");
            }
        }
        printf("String is a palindrome!");
    }
    else
    {
        printf("length is odd");
    }
}
