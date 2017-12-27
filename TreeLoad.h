//µ«¬ΩΩÁ√Ê…Ë÷√
void Twinkle(char *a)
{
	int i;
	for(i=0;i<16;i++)
	{
	 cout<<a<<endl;
	 Sleep(100);
	 Sleep(100);
	}
	return ;
}
void Twinkle1(char *a)
{
	int i;
	for(i=0;i<6;i++)
	{
	system("cls");	
	 cout<<a<<endl;
	 Sleep(100);
	 system("cls");	
	 Sleep(100);
	}
	return ;
}
void ShowGraph()
{
	char A[100]="     Pika		Pika			Pika			Pika";
	Twinkle(A);
	Twinkle1(A);
	printf("     `;-.          ___.	                            ,___          .-;'\n"); 

	printf("       `.`\\_...._/`.-\"                              `\"-.`\\_...._/`.`\n"); 

	printf("         \\        /      ,	                 ,      \\        /\n"); 

	printf("         /()   () \\    .' `-._               _.-' ',    / ()   ()\\\n"); 

	printf("        |)  .    ()\\  /   _.'	              '._   \\  /()    .  (|\n");  

	printf("        \\  -'-     ,; '. <                       > .' ;,     -'-  /\n");     

	printf("         ;.__     ,;|   >                       / <   |;,     __.;\n");      

	printf("        / ,    / ,  |.-'.-'                     '-.'-.|  , \    , \\\n");     

	printf("       (_/    (_/ ,;|.<`                           `>.|;, \\_)    \\_)\n");        

	printf("         \\    ,     ;-`                             `-;     ,    /\n");        

	printf("          >   \\    /                                   \\    /   <\n");           

	printf("         (_,-'`> .'                                     '. <`'-,_)\n");              

	printf("              (_,'                                       '._)\n");              

	cout<<A<<endl;
	char a;
	cout<<"			Are you ready? Let's GO!!!"<<endl;
	cout<<"			Press any key to enter....."<<endl<<"				";
	cin>>a;
	return ;
}
void ShowLoad()
{
	system("cls");
	int a,i;
	i=0;
	char truekey[20]="5W1M";
	char key[20];
	cout<<"			You only have Three chances to TRY!!!"<<endl;
	while(1)
	{
	if(i>=3)
	{
		cout<<"			You can't enter the system!!!"<<endl;
		exit(0);
	}
	cout<<"			®x®y®z®{®|®}®~®Ä®Ä®Ä®Ä®Ä®Ä®Ä®~®}®|®{®z®y®x		"<<endl;
	cout<<"			Please input the key "<<endl<<"			Key is:";
	cin>>key;
	i++;
	if(strcmp(key,truekey)!=0)
	{
		cout<<"			The key is wrong!!!"<<endl;
		cout<<"			Do you want to keep on inputing? <0/1>";
		cin>>a;
		if(a==0)
		{
			cout<<"			You can't enter the system!!!"<<endl;
			exit(0);
		}
	}
	else
	{
		cout<<"			Welcome to the system!!!"<<endl;
		break;
	}
	}
	return;
}