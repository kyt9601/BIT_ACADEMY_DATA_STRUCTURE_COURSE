/*#include <iostream>

#include <string>

using namespace std;

void main()
{
	string str[26] =
	{
	"Vincent",
	"Wily" ,
	"Bill",
	"Umberto",
	"Kuper",
	"David",
	"Elvis",
	"Helen",
	"Xxx",
	"Yuki",
	"Isabel",
	"Rambo",
	"Scarlet",
	"Jane",
	"Louic",
	"Mathilda",
	"Olive",
	"Pablo",
	"Fred",
	"Carol",
	"Gabriel",
	"Queen" ,
	"Trisha",
	"Nadia",
	"Zorro",
	"Alice"
	};

	// 버블 정렬
//	for (int i=0; i<25; i++)
//	{
//		for (int j=i+1; j<26; j++)
//		{
//			if (str[i][0] > str[j][0]) { swap(str[i],str[j]); }
//		}
//	}
//
//	for (int k=0; k<26; k++) { cout << str[k] << endl; }

	// 선택 정렬
//	int min_idx;
//
//	for (int i=0; i<25; i++)
//	{
//		min_idx = i;
//
//		for (int j=i+1; j<26; j++)
//		{
//			if (str[j][0] < str[min_idx][0]) { min_idx = j; }
//		}
//
//		swap(str[i],str[min_idx]);
//	}	
//
//	for (int k=0; k<26; k++) { cout << str[k] << endl; }

	// 삽입 정렬
	int temp;
	for (int i=1; i<26; i++)
	{
		temp = i;
		for (int j=i-1; str[temp][0]<str[j][0]; j--)
		{
			if (str[j+1][0] < str[j][0]) { swap(str[j+1],str[j]); }
			else { swap(str[25],str[j]); }
		}
	}	

	for (int k=0; k<26; k++) { cout << str[k] << endl; }
}*/