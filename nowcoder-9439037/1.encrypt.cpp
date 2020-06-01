#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char buf[81];
    cin.getline(buf,81);
    string s(buf);
    for (auto& it : s) {
        if ((it >= 'a'&& it <= 'z') || (it >= 'A' && it <= 'Z')) {
            if (it == 'z') it = 'a';
            else if (it == 'Z') it = 'A';
            else it = it + 1;
        }
    }
    cout << s << endl;
    return 0;
}
///////////
// python
strr=input()
newstr=''
for ch in strr:
    if ch is 'z':
        ch='a'
    elif ch is 'Z':
        ch='A'
    elif ch.isalpha():
        ch=chr(ord(ch)+1)
    newstr+=ch        
print(newstr)
//////////////////
# utf-8 
str2=bytearray(strr, 'ascii')
for index, byte in enumerate(str2):
    if byte==ord('Z'):
        # byte=ord('A')
        byte=ord('A')
    elif byte==ord('z'):
        byte=ord('a')
    elif chr(byte).isalpha():
        byte+=1
    str2[index]=byte
print(str2.decode('ascii'))
print(str(str2, 'ascii'))
