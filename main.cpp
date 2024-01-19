#include <iostream>
#include <cmath>
#include <iomanip>

double task(double *arr, int n)
{
double t = 1;

int s = 0;

for (int i = 0; i < n; i++)
{
if (arr[i] != 0)
t *= arr[i];
else 
s++;
}

if (s != 0)
std::cout << "There are " << s << " zero elements 
in the array" << '\n';
else
std::cout << "Zero elements do not exist in the 
array" << '\n';

t = pow(t, 1 / 3.0);

return t;

}

int sizechecker(int n)
{
while (true)
{
try
{
if (!(std::cin >> n)) // ïðîâåðêà íà áóêâó 
èëè ñïåö.ñèìâîëû
{
std::cin.clear();

while (std::cin.get() != '\n');

throw "Size is non digit!";
}
else
if (n <= 0 || n > 10)
throw "Size is out of range!";
else
break;

}

catch (const char* exception)
{
std::cout << exception << '\n';

std::cout << "Type new size: ";
}
}
return n;
}

int main()
{
int n = 0;

double t;

std::cout << "Type size of the array: ";

n = sizechecker(n);

double* arr = new double[n];

std::cout << "Type elements of the array: ";

for (int i = 0; i < n; i++)
std::cin >> arr[i];

t = task(arr, n);

std::cout << "Geometric mean: " << t;

delete[] arr;

return 0;
}
