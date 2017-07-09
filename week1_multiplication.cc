#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string add (string astr, string bstr){
  int alen = astr.size();
  int blen = bstr.size();
  int p = alen - 1, q = blen - 1, carry = 0;
  string result = "";
  int temp = 0;
  
  while(p >= 0 || q >= 0){
    if (q < 0) temp = astr[p]-'0' + carry;
    if (p < 0) temp = bstr[q]-'0' + carry;
    if (p >= 0 && q >= 0) temp = astr[p]-'0' + bstr[q] -'0' + carry;
    if (temp > 9) { carry = temp / 10; temp %= 10; }
    else carry = 0;
    result += temp + '0';
    p--;
    q--;
  }
  if (carry>0) result += carry + '0';
  reverse(result.begin(),result.end());
  return result;
}

string addZero (string s, int num){
  for (int i=0; i<num; i++) s += "0";
  return s;
}

string multiply (string astr, string bstr){
  if (astr.size() > 2 || bstr.size() > 2){
    int alen = astr.size(), blen = bstr.size();
    int ahalf = alen/2, bhalf = blen/2;
    string a = "", b = "", c = "", d = "";
    for (int i=0; i<alen-ahalf; i++) a += astr[i];
    for (int i=ahalf; i<alen-1; i++) b += astr[i];
    for (int i=0; i<blen-bhalf; i++) c += bstr[i];
    for (int i=bhalf; i<blen-1; i++) d += bstr[i];
    //recursivly multiply
    // astr = a * 10^(n/2) + b; bstr = c * 10^(n/2) + d
    // astr * bstr = a*c*10^(n) + (b*c + a*d)*10^(n/2) + b*d
    string result1 = addZero(multiply(a,c),ahalf+bhalf);
    string result2 = addZero(multiply(a,d),ahalf);
    string result3 = addZero(multiply(b,c),bhalf);
    string result4 = multiply(b,d);
    result1 = add(result1, result2);
    result2 = add(result3, result4);
    return add(result1, result2);
    
  } else {
    int a = stoi(astr);
    int b = stoi(bstr) * a;
    return to_string(b);
  }  
}

int main(){
  string a = "", b = "";
  cin >> a >> b;
  cout << endl << "Result is :" <<endl
       << multiply(a,b) <<endl;
  return 0;
}
