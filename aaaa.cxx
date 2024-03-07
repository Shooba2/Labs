#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;


void fill_array(int* arr, int n)
{
	int rand_arr[5000];
	for (int i = 0; i < 5000; i++)
	{
		rand_arr[i] = i+1;
	}
	unsigned seed = 1001;
	std::default_random_engine rng (seed);
	std::uniform_int_distribution <unsigned> dstr(1, 5001);

	for(unsigned counter = n; counter != 0; --counter)
		{
		arr[counter] = rand_arr[dstr(rng)] % n;
		}
}

void sum_fill_array(int* arr, int n)
{
	int rand_arr[5000];
	for (int i = 0; i < 5000; i++)
	{
		rand_arr[i] = i+1;
	}
	unsigned seed = 1001;
	std::default_random_engine rng (seed);
	std::uniform_int_distribution <unsigned> dstr(1, 5001);

	for(unsigned counter = n; counter != 0; --counter)
		{
		arr[counter] = rand_arr[dstr(rng)] % n;
		}
}

int lin_search(int* arr, int n, int x, int j)
{
	float lin_time = 0;
	for (int k = 0; k < j; k++)
	{
		fill_array(arr, n);
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		for (int i = 0; i < n; i++)
		{
			if (x == arr[i]) break;
		}
			auto end = std :: chrono :: steady_clock :: now();
			auto time_span =
		std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
		lin_time += time_span.count()/1000;
		std::cout << "lin" ;
		std::cout << time_span.count() << std::endl;
	}
	return (lin_time)/j/1000;
}

int bin_search(int* arr, int n, int x, int j)
{
	int lin_time = 0;
	for (int k = 0; k < j; k++)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		for (int i = 0; i < n; i++)
		{
			int l = 0;
			int r = n-1;
			int mid = 0;
			while(r - l > 1)
			{
				mid = (l + r) / 2;
				if(arr[mid] > x)
					r = mid;
				else
					l = mid;
			}
			if(arr[l] == x)
				break;
			break;
		}
		auto end = std :: chrono :: steady_clock :: now();
        auto time_span =
        std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
        lin_time += time_span.count();
        std::cout << "\n" ;
        std::cout << time_span.count() << std::endl;

		}
	return lin_time/j/1000;
	}


int worst_bin_search(int* arr, int n, int j)
{
	int lin_time = 0;
	for (int k = 0; k < j; k++)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		for (int i = 0; i < n; i++)
		{
			int l = 0;
			int r = n-1;
			int mid = 0;
			while(r - l > 1)
			{
				mid = (l + r) / 2;
				if(arr[mid] > 0)
					r = mid;
				else
					l = mid;
			}
			if(arr[l] == 0)
				break;
			break;
		}
		auto end = std :: chrono :: steady_clock :: now();
        auto time_span =
        std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
        lin_time += time_span.count();
        std::cout << "\n" ;
        std::cout << time_span.count() << std::endl;

		}
	return lin_time/j/1000;
	}

int worst_lin_search(int* arr, int n)
{
	int lin_time = 0;
	for (int k = 0; k < 3; k++)
	{
		fill_array(arr, n);
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		for (int i = 0; i < n; i++)
		{
			if (0 == arr[i]) break;
		}
		auto end = std :: chrono :: steady_clock :: now();
        auto time_span =
        std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
        lin_time += time_span.count()/1000;
        std::cout << "\n" ;
        std::cout << time_span.count() << std::endl;

	}
	return lin_time/3;
}

int sum_lin_search(int* arr_sum, int n, int x, int j)
{
	float lin_time = 0;
	for (int k = 0; k < j; k++)
	{
		sum_fill_array(arr_sum, n);
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		for (int i = 0; i < n; i++)
		{
			for (int g = 0; g < n; g++)
			{	
				if (x == arr_sum[i] + arr_sum[g]) break;
			}
		}
			auto end = std :: chrono :: steady_clock :: now();
			auto time_span =
		std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
		lin_time += time_span.count()/1000;
		std::cout << "\n" ;
		std::cout << time_span.count() << std::endl;
	}
	return (lin_time)/j;
}

int sum_bin_search(int* arr_sum, int n, int x, int j)
{
	float lin_time = 0;
	for (int k = 0; k < j; k++)
	{
		for (int i = 0; i < n; i++)
		{
			arr_sum[i] = i;
		}
		auto begin = std :: chrono :: steady_clock :: now();
		for (unsigned cnt = 100000; cnt != 0 ; --cnt)
		{
			int l = 0, r = n - 1;
			while(r != -1)
			{
				while(l < r && arr_sum[l] + arr_sum[r] < x)
				{
					++l;
				}
				if(arr_sum[l] + arr_sum[r] == x)
					break;
				--r;
			}
			break;
		}
		auto end = std :: chrono :: steady_clock :: now();
		auto time_span =
		std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin);
		lin_time += time_span.count();
		std::cout << "\n" ;
		std::cout << time_span.count() << std::endl;
	}
	return (lin_time)/j;
}






void lin_time_search(int* lin_arr, int* arr)
{
	for (int i = 1; i < 26; i++)
	{
		int n = i*200;
		int j = 10000/n;
		int x = 1 + rand() % n;
		lin_arr[i] = lin_search(arr, n, x, j);
	}
}

void bin_time_search(int* lin_arr, int* arr)
{
	for (int i = 1; i < 26; i++)
	{
		int n = i*200;
		int j = 10000/n;
		int x = 1 + rand() % n;
		lin_arr[i] = bin_search(arr, n, x, j);
	}
}

void worst_bin_time_search(int* lin_arr, int* arr)
{
	for (int i = 1; i < 26; i++)
	{
		int n = i*200;
		lin_arr[i] = worst_bin_search(arr, n, 10);
	}
}

void worst_lin_time_search(int* lin_arr, int* arr)
{
	for (int i = 1; i < 26; i++)
	{
		int n = i*200;
		lin_arr[i] = worst_lin_search(arr, n);
	}
}

void sum_lin_time_search(int* lin_arr, int* arr_sum)
{
	for (int i = 1; i < 6; i++)
	{
		int n = i*500;
		int j = 5000/n;
		int x = 1 + rand() % n;
		lin_arr[i] = sum_lin_search(arr_sum, n, 2*x, j);
	}
}

void sum_bin_time_search(int* lin_arr, int* arr_sum)
{
	for (int i = 1; i < 26; i++)
	{
		int n = i*200;
		int j = 10000/n;
		int x = 1 + rand() % n;
		lin_arr[i] = sum_bin_search(arr_sum, n, 2*x, j);
	}
}



int main()
{
	int* arr = new int[5000];
	int* lin_arr = new int[26];
	/*lin_time_search(lin_arr, arr);
	for (int i = 1; i < 26; i++)
	{
        ofstream outfile;
        outfile.open("lin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}
	worst_lin_time_search(lin_arr, arr);
	for (int i = 1; i < 26; i++)
	{
	    ofstream outfile;
        outfile.open("worst_lin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}
	bin_time_search(lin_arr, arr);
	for (int i = 1; i < 26; i++)
	{
	    ofstream outfile;
        outfile.open("bin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}
	worst_bin_time_search(lin_arr, arr);
	for (int i = 1; i < 26; i++)
	{
	    ofstream outfile;
        outfile.open("worst_bin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}
	int* arr_sum = new int[2500];
	sum_lin_time_search(lin_arr, arr_sum);
	for (int i = 1; i < 6; i++)
	{
	    ofstream outfile;
        outfile.open("sum_lin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}*/
	sum_bin_time_search(lin_arr, arr);
	for (int i = 1; i < 26; i++)
	{
	    ofstream outfile;
        outfile.open("sum_bin_timeCB.txt", std::ios_base::app);
        outfile << lin_arr[i] << "\n";
	}
	return 0;
}
