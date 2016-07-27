int askAgain()
{
  	char Repeat;

  	do // Loop for asking unill a correct char is given
    {

      printf("Wollen Sie noch einmal? (j/n): \n");
      

      scanf("%[^\n]", &Repeat);

      if (Repeat == '\n')
        ClearBuffer();

      ClearBuffer();

      if (Repeat == 'j' || Repeat == 'J') 
      {
        return 1;
      } 
      else 
        if (Repeat == 'n' || Repeat == 'N') 
        {
        return 0;
        }

    } while (1);
}
