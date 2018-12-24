#include <bits/stdc++.h>
using namespace std;
	
	string sl[100];
	string s, max_sl;
	int k_sl = 0;
	
int input_word(string s0, string arr_sl[]){
	int dl = s0.length(), k=0;
	string s1 = "";
	for(int i=0;i<=dl;i++){
		if(s0[i]!=',' && s0[i]!='.' && s0[i]!=' '){
			s1 += s0[i];
		}		
		else{
			if((s0[i]==',' || s0[i]=='.' || s0[i]==' ') && 
				(s0[i-1]==',' || s0[i-1]=='.' || s0[i-1]==' ')){
				continue;
			}
			arr_sl[k] = s1;
			k++;
			s1 = "";
		}		
	}
	arr_sl[k] = s1;
	k_sl = k+1;
	return k_sl;
}

void del_word(string arr_sl[], int arr_dl){
	for(int i=0;i<arr_dl;i++){
		if(i%2 == 0){
			arr_sl[i] = "";
		}
	}
}

string find_max_word(string arr_sl[], int arr_dl, string max_word){
	int dl_max_word = max_word.length();
	for(int i=0;i<arr_dl;i++){
		int dl_sl = arr_sl[i].length();		
		if(dl_max_word < dl_sl){			
			max_word = arr_sl[i];	
			dl_max_word = max_word.length();
		}
	}
	return max_word;
}
	
int main (){	
	getline(cin, s);	
	input_word(s, sl);		
	del_word(sl,k_sl);	
	max_sl = "";
	cout << find_max_word(sl, k_sl, max_sl) << endl;	
	
	return 0;
}
