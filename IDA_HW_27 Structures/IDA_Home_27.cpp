#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

struct Movie
{
	std::string Title = "no title";
	int Year_Production = -1;
	std::string Genre = "no genre";
	unsigned int Duration_min = -1;
	unsigned int Making_Budget_mln_$ = -1;
};
/* // ??? Так нельзя чтоли ???
Movie Terminator_2
{
	Terminator_2.Title = "Terminator 2: Judgment Day",
	Terminator_2.Year_Production = 1991,
	Terminator_2.Genre = "science-fiction action",
	Terminator_2.Duration_min = 137,
	Terminator_2.Making_Budget_mln_$ = 102
};
/*/
Movie Terminator_2 //0
{
	"Terminator 2: Judgment Day",
	1991,
	"science-fiction action",
	137,
	102
};
Movie FClub //1
{
"Fight Club",
1999,
"thriller, drama, crime",
139,
65
};
Movie Gladiator //2
{
	"Gladiator",
	2000,
	"epic historical drama",
	155,
	103
};


int const numbers_of_movies = 3;

Movie movies_stack[numbers_of_movies] = {Terminator_2,FClub,Gladiator};

//Movie& movies_stack[numbers_of_movies] = { Terminator_2,FClub,Gladiator };

Movie* movies_stack[numbers_of_movies] = { &Terminator_2,&FClub,&Gladiator };



// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 27 ----------------------------------------------------	
void show_movie(Movie this_movie);
Movie expensive(Movie movie_1, Movie movie_2, Movie movie_3);
void update_info(Movie& movie_1);

void show_movie_list()
{
	std::cout << "Movie list:\n";

	Movie tmp;

	for (int i = 0; i < numbers_of_movies; i++)
	{
		tmp = *movies_stack[i];

		//std::cout << i + 1 << ". " << movies_stack[i].Title << "\n"; //without pointers variant. works

		/*
		std::cout << i + 1 << ". " << *movies_stack[i].Title << "\n";
		std::cout << i + 1 << ". " << *(movies_stack[i].Title) << "\n";
		std::cout << i + 1 << ". " << *(movies_stack[i]).Title << "\n";
		*/
		std::cout << i + 1 << ". " << tmp.Title << "\n";
	}
}

//Task 1
void show_movie()
{
	show_movie_list();
	for (int i = 0; i < 50; i++)
		std::cout << "-";

	std::cout << "\nChoose a movie to show info: ";
	int movie_choice = Get_Int_Positive();

	if (movie_choice>0&& movie_choice<= numbers_of_movies)
	//show_movie(movies_stack[movie_choice - 1]); //without pointers variant. works
	show_movie(*movies_stack[movie_choice - 1]);
	else std::cout << "\nInvalid movie choice\n";

	/*
	switch (movie_choice)
	{
	case 1: show_movie(Terminator_2); break;
	case 2: show_movie(FClub); break;
	case 3: show_movie(Gladiator); break;
	default: std::cout << "\nInvalid movie choice\n";
	}
	*/
}
void show_movie(Movie this_movie)
{
	std::cout << "\n" << "1. Title:               " << this_movie.Title;
	std::cout << "\n" << "2. Year of Production:  " << this_movie.Year_Production;
	std::cout << "\n" << "3. Genre:               " << this_movie.Genre;
	std::cout << "\n" << "4. Duration, min:       " << this_movie.Duration_min;
	std::cout << "\n" << "5. Making budget, mln$: " << this_movie.Making_Budget_mln_$;
	std::cout << "\n";
}

//Task 2
/*
void expensive()
{
	std::cout<< "\nBiggest budget movie: "<< expensive(Terminator_2, FClub, Gladiator).Title<<
		"\nBudget is: " << expensive(Terminator_2, FClub, Gladiator).Making_Budget_mln_$ << " millions $";
}
Movie expensive(Movie movie_1, Movie movie_2, Movie movie_3)
{
	Movie tmp=movie_1;
	if (movie_2.Making_Budget_mln_$ > tmp.Making_Budget_mln_$)
		tmp = movie_2;
	if (movie_3.Making_Budget_mln_$ > tmp.Making_Budget_mln_$)
		tmp = movie_3;
	return tmp;
}
*/
void expensive()
{
	show_movie_list();

	//std::cout << "\nBiggest budget movie: " << expensive(movies_stack[0], movies_stack[1], movies_stack[2]).Title <<//without pointers variant. works
	std::cout << "\nBiggest budget movie: " << expensive(*movies_stack[0], *movies_stack[1], *movies_stack[2]).Title <<
		//"\nBudget is: " << expensive(movies_stack[0], movies_stack[1], movies_stack[2]).Making_Budget_mln_$ << " millions $";//without pointers variant. works
		"\nBudget is: " << expensive(*movies_stack[0], *movies_stack[1], *movies_stack[2]).Making_Budget_mln_$ << " millions $";
}
Movie expensive(Movie movie_1, Movie movie_2, Movie movie_3)
{
	Movie tmp = movie_1;
	//for (int i=0;i<numbers_of_movies; i++)
	if (movie_2.Making_Budget_mln_$ > tmp.Making_Budget_mln_$)
		tmp = movie_2;
	if (movie_3.Making_Budget_mln_$ > tmp.Making_Budget_mln_$)
		tmp = movie_3;
	return tmp;
}

//Task 3
void update_info()
{
	show_movie_list();

	for (int i = 0; i < 50; i++)
		std::cout << "-";

	std::cout << "\nChoose a movie to change info: ";
	int movie_choice = Get_Int_Positive();

	if (movie_choice > 0 && movie_choice <= numbers_of_movies)
		//update_info(movies_stack[movie_choice - 1]);	//without pointers variant. works
		update_info(*movies_stack[movie_choice - 1]);
	else std::cout << "\nInvalid movie choice\n";		
}
void update_info(Movie& movie_1)
{
	show_movie(movie_1);

	for (int i = 0; i < 50; i++)
		std::cout << "-";
	std::cout << "\nChoose what info to change: ";	
	int info_change_choice = Get_Int_Positive();

	//int n = fieldCount(movie_1); ??? можно ли как-то узнать кол-во полей в структуре ???

	switch (info_change_choice)
	{
	case 1: std::cout << "\nEnter new Title -> "; getline(std::cin, movie_1.Title); break;
	case 2: std::cout << "\nEnter new Year of production -> "; movie_1.Year_Production = Get_Int_Positive(); break;
	case 3: std::cout << "\nEnter new Ganre -> "; getline(std::cin, movie_1.Genre); break;
	case 4: std::cout << "\nEnter new Duration -> "; movie_1.Duration_min = Get_Int_Positive(); break;
	case 5: std::cout << "\nEnter new Making Budget -> "; movie_1.Making_Budget_mln_$ = Get_Int_Positive(); break;
	default: std::cout << "\nInvalid info.field number choice\n"; return;

	}
	std::cout << "\nInfo successfully changed\n";
}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=110 lines=40"); 
	std::string Name_of_Work = { "Home Work 27: Structures" };
	std::string Menu_Element_1 = { "show_movie()" };
	std::string Menu_Element_2 = { "expensive()" };
	std::string Menu_Element_3 = { "update_info()" };
	//std::string Menu_Element_4 = { "XXX" };

	do {		
		system("cls");
		std::cout << "\n\t***\t" << Name_of_Work << "\t***\n\n\t\n\nChoose an option: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		//std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n\n 0. Exit\n";
		
		
		for (int i = 0; i < 50; i++)
			std::cout << "-";

		
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		
		//show_movie_list();
		
		
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) show_movie();
		else if (choice == 2) expensive();
		else if (choice == 3) update_info();
		//else if (choice == 4) Search_First_Ordinary_in_Array_demo();
			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
		
	//system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
