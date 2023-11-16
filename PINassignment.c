#include <stdio.h>

#define SIZE 4

//Function signatures
void option1(int new_code[SIZE]);

void option2(int new_code[SIZE], int access_code[SIZE], int *correct, int *incorrect);

void option3(int new_code[SIZE]);

void option4(int *correct, int *incorrect);


int main(void)
{
    //initialising variables
    int access_code[SIZE] = {4,5,2,3};
    int new_code[SIZE];
    int menu = 0;
    int i;
    int correct = 0;
    int incorrect = 0;
    int already_encrypted = 0;
    int already_decrypted = 0;
    
    //While loop returns user to menu after each option is finished
    while (menu = 1 || 2 || 3 || 4 || 5)
    {   
        //Displaying a menu
        printf("\nPlease choose an option\n");
        printf("Press 1 to enter a code\n");
        printf("Press 2 to encrypt code entered\n");
        printf("Press 3 to decrypt code\n");
        printf("Press 4 to display number of times code was entered successfully and unsuccessfully\n");
        printf("Press 5 to terminate the program\n");
        scanf("%d", &menu);
    
        //Switch allows user to select an option from the menu
        switch(menu)
        {
            case 1:
            {
                option1(new_code);
                already_encrypted = 2;
                already_decrypted = 3;
                break;
            }
            
            case 2:
            {
                if(already_encrypted == 0)
                {
                    printf("Error, code required for encryption\n");
                    break;
                }//End if
                else if(already_encrypted == 1)
                {
                    printf("Code already encrypted\n");
                    break;    
                }//End else if
                else
                {
                    option2(new_code,access_code, &correct, &incorrect);
                    //Once encrypted, user cannot encrypt again 
                    already_encrypted = 1;
                    //Allows encrypted code to be decrypted again
                    already_decrypted = 2;
                    break;
                }//End else
            }//end case 2
            
            case 3:
            {
                if(already_decrypted == 0)
                {
                    printf("Error, code required for decryption\n");
                    break;
                }//End if
                else if(already_decrypted == 1)
                {
                    printf("Code already decrypted\n");
                    break;
                }//End else if
                else if(already_decrypted == 3)
                {
                    printf("Error, Code must be encrypted first\n");
                    break;
                }
                else
                {
                    option3(new_code);
                    //Once decrypted, user cannot decrypt again
                    already_decrypted = 1;
                    //Allows decrypted code to be encrypted again
                    already_encrypted = 2;
                    break;
                }//End else
            }//end case 3
            
            case 4:
            {
                option4(&correct, &incorrect);
                break;
            }//end case 4
            
            case 5:
            {
                printf("\nProgram Terminated\n");
                return 0;
            }//end case 5
            
            default:
            {
                printf("Error, please try again\n");
                break;
            }//end default
            
        }//end switch
        
    }//end while 
    

    return 0;
}//End main

//Function 1 to enter a code 
void option1(int new_code[SIZE])
{
    int i;
    
    printf("Enter a four digit code, one per line\n");

    for(i = 0; i < SIZE; i++)
    {
        scanf("%d", (&*(new_code+i)));
    }//End for 
    
}//End function 1

//Function 2 to encrypt and verify code
void option2(int new_code[SIZE], int access_code[SIZE], int *correct, int *incorrect)
{
    int i;
    int temp_code;
    int equal = 0;
    
    //Swap the first and third numbers
    temp_code = *(new_code);
    *(new_code) = *(new_code+2);
    *(new_code+2) = temp_code;
    
    //Swap the second and fourth numbers
    temp_code = *(new_code +1);
	*(new_code+1) = *(new_code+3);
	*(new_code+3) = temp_code;
	//Adds 1 to each number
	for(i = 0; i < 4; i++)
	{
	    (*(new_code+i))++;
	}//end for 
	
	//If any number becomes ten, loop changes it to zero
	for(i = 0; i < 4; i++)
	{
	    if((*(new_code+i)) > 9)
	    {
	        (*(new_code+i)) = 0;
	    }//End if
	}//End for 
	
	//Compares user input to access code 
	for(i = 0; i < 4; i++)
	{    
		if((*(new_code+i)) == (*(access_code+i)))
		{
		   //equal counter increases for each matching number
		   equal = equal + 1;
		}//End if
	}//End for 

	//Registers if both codes are equal to each other 
	if(equal == 4)
	{
		printf("\nCorrect Code entered\n");
		(*correct)++;
	}//End if 
	else
	{
		printf("\nWrong Code entered\n");
		(*incorrect)++;
	}//End else 
	
}//end function 2

//Function 3 to decrypt the code
void option3(int new_code[SIZE])
{
    int temp_code2;
    int i;
    
    for(i = 0; i < 4; i++)
    {
        (*(new_code + i))--;
    }//End for
    
    //Changes number from -1 to 9
    for(i = 0; i < 4; i++)
	{
	    if((*(new_code+i)) < 0)
	    {
	        (*(new_code+i)) = 9;
	    }//End if
	}//End for 
	
	//Swap the first and third numbers
    temp_code2 = *(new_code);
    *(new_code) = *(new_code+2);
    *(new_code+2) = temp_code2;
    
    //Swap the second and fourth numbers
    temp_code2 = *(new_code +1);
	*(new_code+1) = *(new_code+3);
	*(new_code+3) = temp_code2;
	
	printf("Code decrypted\n");
    
}//End function 3

//Function 4 displays the number of correct and incorrect times the user code matches the access code
void option4(int *correct, int *incorrect)
{
    printf("\nCode entered Correctly is %d\n", *correct);
    printf("\nCode entered Incorrectly is %d\n", *incorrect);
}//End Function 4
