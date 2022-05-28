#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ArraySize 100

//******************************************
void read_diamerismata(int Raddress_number[ArraySize],char Raddress_name[ArraySize][ArraySize],char Rdiamerisma_characteristics[ArraySize][ArraySize],int Rdiamerismata_count);
void read_customer(char Rcustomer_characteristics[ArraySize]);
bool validation(char char_check[ArraySize]);
void sygrisi(char Sdiamerisma_characteristics[ArraySize][ArraySize],char Scustomer_characteristics[ArraySize],int wanted_apartment[ArraySize],int Sdiamerismata_count); 
int AddressChar_count(const int Aaddress_number[ArraySize],char Aaddress_name[ArraySize][ArraySize],int Aaddress_size[ArraySize],int Adiamerismata_count);
void display(const int Daddress_number[ArraySize],char Daddress_name[ArraySize][ArraySize],const int Rwanted_apartment[ArraySize],int Ddiamerismata_count);
//******************************************

//******************************************
int main()
{
	int address_number[ArraySize],diamerismata_count,wanted_apartment[ArraySize]={0};
	char address_name[ArraySize][ArraySize],diamerisma_characteristics[ArraySize][ArraySize]={'\0'},customer_characteristics[ArraySize]={'\0'};
	
	//Read how many apartments are left
	printf("Enter the amount of apartments: ");
	scanf("%d",&diamerismata_count);
	printf("\n");
	
	//Read apartments' details
	read_diamerismata(address_number,address_name,diamerisma_characteristics,diamerismata_count);
	
	//Read customer's details
	read_customer(customer_characteristics);
	
	//Sigrisi pelaton me diamerismaton
	sygrisi(diamerisma_characteristics,customer_characteristics,wanted_apartment,diamerismata_count);
	
	system("CLS");
	
	//Print the table
	display(address_number,address_name,wanted_apartment,diamerismata_count);
	
	system("pause");
	return 0;
}
//******************************************

//******************************************
bool validation(char char_check[ArraySize])
{
	int char_count=0;
	bool input_check=true;
		
	do{
			if(char_check[char_count]!='Y' && char_check[char_count]!='N' && char_check[char_count]!='\0')
			{
				input_check=false;
			}
				char_count++;
	}while(char_check[char_count]!='\0');
	
	if(!input_check)
	{
		printf("Wrong Input!\n");
	}
	
	if(char_count<30 || char_count>30)
	{
		input_check=false;
		printf("Missing letters or Too much letters!\n");
	}
	
	return input_check;
	
}
//******************************************

//******************************************
void read_diamerismata(int Raddress_number[ArraySize],char Raddress_name[ArraySize][ArraySize],char Rdiamerisma_characteristics[ArraySize][ArraySize],int Rdiamerismata_count)
{
	int counter,char_count;
	bool correct_input=true;
	char temp_char;
	
	for(counter=0;counter<Rdiamerismata_count;counter++)
	{
		//Read characteristics
		do{
			char_count=0;
			
			printf("Enter the characteristics of apartment[%d]: ",counter);
			scanf("%s",&Rdiamerisma_characteristics[counter]);
			
			correct_input=validation(Rdiamerisma_characteristics[counter]);
			
		}while(!correct_input);
		
		//Read address number
		printf("Enter address number of apartment[%d]: ",counter);
		scanf("%d",&Raddress_number[counter]);
		
		//temp_char is to save the enter in order to read the address name
		scanf("%c",&temp_char);
		
		//Read address name
		char_count=0;
		printf("Enter address name of apartment[%d]: ",counter);
		scanf("%[^\n]",Raddress_name[counter]);
		printf("\n");
	}
}
//******************************************

//******************************************
void read_customer(char Rcustomer_characteristics[ArraySize])
{
	int counter,char_count;
	bool correct_input=true;
	
		//Read characteristics
		do{
			char_count=0;
			correct_input=true;
			
			printf("Enter the needs of the customer: ");
			scanf("%s",Rcustomer_characteristics);
			
			correct_input=validation(Rcustomer_characteristics);
			
		}while(!correct_input);
		
}
//******************************************

//******************************************
void sygrisi(char Sdiamerisma_characteristics[ArraySize][ArraySize],char Scustomer_characteristics[ArraySize],int wanted_apartment[ArraySize],int Sdiamerismata_count)
{
	int counterout,counterin,compare;
	
	for(counterout=0;counterout<Sdiamerismata_count;counterout++)
	{
		for(counterin=0;counterin<30;counterin++)
		{
		
			if(Scustomer_characteristics[counterin]==Sdiamerisma_characteristics[counterout][counterin])
			{
				wanted_apartment[counterout]++;
			}
		}
	}
}
//******************************************

//******************************************
void display(const int Daddress_number[ArraySize],char Daddress_name[ArraySize][ArraySize],const int Dwanted_apartment[ArraySize],int Ddiamerismata_count)
{
	int counter,icount,maxaddress_sizes,address_size[ArraySize]={0};
	
	//Call the function AddressChar_count to find the size of every address and the maximum size
	maxaddress_sizes=AddressChar_count(Daddress_number,Daddress_name,address_size,Ddiamerismata_count);
	
	printf("Address");
	if(maxaddress_sizes-7>0)
	{
		for(icount=0;icount<maxaddress_sizes-4;icount++)
		{
			printf(" ");
		}
	}
	else
	{
		maxaddress_sizes=7;
		printf("   ");
	}
	printf("Amount of customer\tPOSSIBLE/NO\n");
	
	for(counter=0;counter<Ddiamerismata_count;counter++)
	{
		printf("%d%s",Daddress_number[counter],Daddress_name[counter]);
		for(icount=0;icount<maxaddress_sizes-address_size[counter];icount++)
		{
			printf(" ");
		}
		printf("%21d",Dwanted_apartment[counter]);
		
		
		if((Dwanted_apartment[counter]*100/30)>=80)
		{
			printf("\tPOSSIBLE\n");
		}
		else
		{
			printf("\tNO\n");
		}
	}
}
//******************************************

//******************************************
int AddressChar_count(const int Aaddress_number[ArraySize],char Aaddress_name[ArraySize][ArraySize],int Aaddress_size[ArraySize],int Adiamerismata_count)
{
	int counter,Amaxaddress_size,char_count=0,temp_adnumber;
	
	//Calculate the size of every address
	for(counter=0;counter<Adiamerismata_count;counter++)
	{
		char_count=0;
		temp_adnumber=Aaddress_number[counter];
		
		//Calculate the size of address number
		while(temp_adnumber>0)
		{
			Aaddress_size[counter]++;
			temp_adnumber/=10;
		}
		
		//Calculate the size of address name
		while(Aaddress_name[counter][char_count]!='\0')
		{
			Aaddress_size[counter]++;
			char_count++;
		}
	}
	
	//Find the maximum size of address
	Amaxaddress_size=Aaddress_size[0];
	for(counter=1;counter<Adiamerismata_count;counter++)
	{
		if(Amaxaddress_size<Aaddress_size[counter])
		{
			Amaxaddress_size=Aaddress_size[counter];
		}
	}
	
	return Amaxaddress_size;
}
//******************************************
