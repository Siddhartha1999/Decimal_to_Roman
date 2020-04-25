#include<stdio.h>
#include<stdlib.h>
#define MS 50
//..........................................................main fucntion
int main(void)
{
  int number, choice, status;
  char roman[MS], temp[MS];

  void dec_roman(int, char []);
  void char_arr_disp(char []);
  int menu(void);
  void about(void);
  void input_str(char []);
  void convert_caps(char str[]);
  int roman_valid(char str[]);
  void roman_to_dec(char [], int *);
  void char_integer(char [], int *);
  int valid_char_int(char []);

  do
  {
    system("clear");
    choice = menu();
    switch( choice )
    {
      case 1:
             do
             {
               system("clear");
               printf("\n\n\t\t Enter the Decimal Integer = ");
               input_str(temp);
               status = valid_char_int(temp);
               if( status == 0 ) { printf("\n\n\t\t Invalid Data, Please enter an Integer "); getchar(); }
             }
             while( status == 0 );
             char_integer(temp, &number);
             dec_roman(number, roman);
             printf("\n\n\t\t The Roman number is = ");
             char_arr_disp(roman);
             printf("\n\n");
             break;
     
      case 2:
             do
             {
               system("clear");
               printf("\n\n\t\t Enter the roman number = ");
               input_str(roman);
               convert_caps(roman);
               status = roman_valid(roman);
               if( status == 0 ) { printf("\n\n\t\t Invalid Data Please enter a Roman Number "); getchar(); }
             }
             while( status == 0 );
             roman_to_dec(roman, &number);
             printf("\n\n\t\t The Decimal is = %d \n\n", number);
             break;

      case 3:
             system("clear");
             about();           
             break;
  
      case 4:
             printf("\n\n\t\t Are you sure want to exit ? ");
             printf("\n\n\t\t Enter '1' for yes, else press '0' = ");
             scanf("%d", &number);
             if( number == 1 ) printf("\n\n\t\t Exit Successfully.....");
             else choice = 0;
             getchar();
             break;

      default : printf("\n\n\t\t Please see the options carefully....");
    }
    if( choice != 4 )
    {
      printf("\n\n\t\t Press Enter to continue.....");
      getchar();
    }
  }while( choice != 4 );

  printf("\n\n\n");
  return(0);
}
//............................................................Build_Look_up table function
void table_build(int num[], char *symb[])
{
  num[0]  = 1;    symb[0]  = "I";
  num[1]  = 4;    symb[1]  = "IV";
  num[2]  = 5;    symb[2]  = "V";
  num[3]  = 9;    symb[3]  = "IX";
  num[4]  = 10;   symb[4]  = "X";
  num[5]  = 40;   symb[5]  = "XL";
  num[6]  = 50;   symb[6]  = "L";
  num[7]  = 90;   symb[7]  = "XC";
  num[8]  = 100;  symb[8]  = "C";
  num[9]  = 400;  symb[9]  = "CD";
  num[10] = 500;  symb[10] = "D";
  num[11] = 900;  symb[11] = "CM";
  num[12] = 1000; symb[12] = "M";
  return;
}
//.......................................................put_string function
void put_str(char str[], int *j, char *symb[], int i)
{
  int p;
  for( p = 0; symb[i][p] != '\0'; p++, (*j)++ ) str[(*j)] = symb[i][p];
  return;
}
//........................................................Decimal to Roman fucntion
void dec_roman(int N, char roman[])
{
  int num[13], i, p;
  char *symb[13];
  void table_build(int [], char *[]);
  void put_str(char [], int *, char *[], int);
  table_build(num, symb);
  p = 0;
  while( N != 0 )
  {
    for( i = 0; (i != 13) && ( num[i] <= N ); i++ ) { }
    i--;
    put_str(roman, &p, symb, i);
    N = ( N - num[i] );
  }
  roman[p] = '\0';
  return;
}
//..................................................................character array display function
void char_arr_disp(char a[])
{
  int i;
  for( i = 0; a[i] != '\0'; i++ ) printf("%c", a[i]);
  return;
}
//...................................................................Menu function
int menu(void)
{
  int ch;
  printf("\n\n\t\t Easy Roman Decimal Converter ");
  printf("\n\t\t ============================ ");
  printf("\n\n\t\t 1. Decimal-to-Roman ");
  printf("\n\n\t\t 2. Roman-to-Decimal ");
  printf("\n\n\t\t 3. About ");
  printf("\n\n\t\t 4. Exit ");
  printf("\n\n\t\t ( Press Back to Exit ) ");
  printf("\n\n\t\t Please enter your choice = ");
  scanf("%d", &ch);
  getchar();
  return(ch);
}
//.................................................................about function
void about(void)
{
  printf("\n\n\t\t Easy Roman Decimal converter V-1.0 ");
  printf("\n\t\t ==================================");
  printf("\n\n\t\t Developer : Siddhartha Dhar ");
  printf("\n\t\t             *************** ");
  printf("\n\n\t\t This app is developed using 'C' programming language. ");
  printf("\n\t\t The purpose of this app is to perform conversions between Roman and Decimal easily ");
  printf("\n\t\t This app is completely safe and build only for educational purposes ");
  printf("\n\t\t For any suggestion and feedback please contact ( pumpinglemma.ardens@gmail.com ) ");
  printf("\n\t\t If you want your personalized app that can do mathematical (educationals) "); 
  printf("\n\t\t calculations for you then please contact above mentioned Email. ");
  printf("\n\n\t\t Thank you for using this application....... ");
  return;
}
//......................................................................................string_input function
void input_str(char str[])
{
  int i;
  char ch;
  for( (i = 0), (ch = 'a'); ch != '\n'; i++ )
  {
    ch = getchar();
    str[i] = ch;
  }
  str[i-1] = '\0';
  return;
}
//.........................................................................................convert_caps function
void convert_caps(char str[])
{
  int i;
  for( i = 0; str[i] != '\0'; i++ ) if( str[i] >= 97 && str[i] <= 122 ) str[i] = ( str[i] - 32 );
  return;
}
//.........................................................................................validity_roman function
int roman_valid(char str[])
{
  int i;
  i = 0;
  while( str[i] != '\0' )
    if( (str[i] == 'I') || (str[i] == 'V') || (str[i] == 'X') || (str[i] == 'L') || (str[i] == 'C') || (str[i] == 'D') || (str[i] == 'M') )
      i = (i + 1);
    else return (0);
  return (1); 
}
//..........................................................................................Roman_to Decimal function
void roman_to_dec(char roman[], int *num)
{
  int i, chk;
  int chk_double_pttrn( char [], int );
  int chk_sngl_pttrn( char [], int );
  (*num) = 0;
  for( i = 0; roman[i] != '\0'; i++ )
  {
    chk = chk_double_pttrn(roman, i);
    if( chk != 0 )
    {
      i++;
      (*num) = ( (*num) + chk );
    }
    else
    {
      chk = chk_sngl_pttrn(roman, i);
      (*num) = ( (*num) + chk );
    }
  }
  return;
}
//..........................................................................................check_double function
int chk_double_pttrn( char str[], int i )
{
  if( str[i] == 'I' )
  {
    if( str[i+1] == 'V' ) return 4;
    else if( str[i+1] == 'X' ) return 9;
  }
  else if( str[i] == 'X' )
  {
    if( str[i+1] == 'L' ) return 40;
    else if( str[i+1] == 'C' ) return 90;
  }
  else if( str[i] == 'C' )
  {
    if( str[i+1] == 'D' ) return 400;
    else if( str[i+1] == 'M' ) return 900;
  }
  return 0;
}
//..........................................................................................chk_single_pattern function
int chk_sngl_pttrn( char str[], int i )
{
  if( str[i] == 'I' ) return 1;
  else if( str[i] == 'V' ) return 5;
  else if( str[i] == 'X' ) return 10;
  else if( str[i] == 'L' ) return 50;
  else if( str[i] == 'C' ) return 100;
  else if( str[i] == 'D' ) return 500;
  else if( str[i] == 'M' ) return 1000;
  return 0;
}

//............................................................check_string_integer function
int valid_char_int(char str[])
{
  int i;
  i = 0;
  while( str[i] != '\0' )
    if( str[i] >= 48 && str[i] <= 57 ) i++;
    else return 0;
  return 1;
}
//............................................................Char to Integer Conversion Function
void char_integer(char str[], int *res)
{
  int i;
  i=0;
  (*res)=0;
  while( str[i] != '\0' )
  {
    (*res)=( ((*res)*10) + ( str[i] - 48 ) );
    i=(i+1);
  }
  return;
}
