#include <bits/stdc++.h>
using namespace std;

class BigInteger
{
private:
    vector<int> data;
    bool sign;
public:
    BigInteger();
    BigInteger(int n);
    BigInteger(long long int n);
    BigInteger(string n);
    BigInteger(const BigInteger &n);
    const BigInteger &operator=(int n);
    const BigInteger &operator=(long long n);
    const BigInteger &operator=(string n);
    const BigInteger &operator=(const BigInteger &n);

    const BigInteger &operator+() const;
    friend BigInteger operator+(const BigInteger &a, const BigInteger &b);
    long long int getLength() const;
    friend ostream &operator<<(ostream &out, const BigInteger &n);
};

BigInteger::BigInteger()
{
    data.push_back(0);
}

BigInteger::BigInteger(int n)
{
    if(n>=0){
        sign = true;
    }
    else {
        sign = false;
        n*=-1;
    }
    while (n > 0)
    {
        data.push_back(n % 10);
        n /= 10;
    }
}

BigInteger::BigInteger(long long int n)
{
    if(n>=0){
        sign = true;
    }
    else {
        sign = false;
        n*=-1;
    }
    while (n > 0)
    {
        data.push_back(n % 10);
        n /= 10;
    }
}

BigInteger::BigInteger(string n)
{
    if(n[0]=='-'){
        sign = false;
        n.erase(0);
    }else{
        sign =true;
    }
    for (int i = n.size() - 1; i >= 0; i--)
    {
        char num = n[i];
        if (isdigit(num))
        {
            data.push_back(num - '0');
        }
        else
        {
            throw std::invalid_argument("输入包含非数字字符");
        }
    }
}

BigInteger::BigInteger(const BigInteger &n)
{
    this->data = n.data;
    this->sign = n.sign;
}

const BigInteger &BigInteger::operator=(int n)
{
    if(n>=0){
        sign = true;
    }
    else {
        sign = false;
        n*=-1;
    }
    while (n > 0)
    {
        data.push_back(n % 10);
        n /= 10;
    }
    return *this;
}

const BigInteger &BigInteger::operator=(long long n)
{
    if(n>=0){
        sign = true;
    }
    else {
        sign = false;
        n*=-1;
    }
    while (n > 0)
    {
        data.push_back(n % 10);
        n /= 10;
    }
    return *this;
}

const BigInteger &BigInteger::operator=(string n)
{
    if(n[0]=='-'){
        sign = false;
        n.erase(0);
    }else{
        sign =true;
    }
    for (int i = n.size() - 1; i >= 0; i--)
    {
        char num = n[i];
        if (isdigit(num))
        {
            data.push_back(num - '0');
        }
        else
        {
            throw std::invalid_argument("输入包含非数字字符");
        }
    }
    return *this;
}

const BigInteger &BigInteger::operator=(const BigInteger &n)
{
    this->data = n.data;
    return *this;
}

const BigInteger &BigInteger::operator+() const
{
    return *this;
}

long long int BigInteger::getLength() const
{
    return this->data.size();
}

BigInteger operator+(const BigInteger &a, const BigInteger &b)
{
    long long int max_len = max(a.getLength(), b.getLength());
   
    BigInteger ans;
    int t = 0;
    int aa = 0, bb = 0;
    ans.data.clear();
    for (long long int i = 0; i < max_len; i++)
    {
        if (i < a.getLength())
        {
            aa = a.data[i];
        }
        else
        {
            aa = 0;
        }
        if (i < b.getLength())
        {
            bb = b.data[i];
        }
        else
        {
            bb = 0;
        }
        int num = aa + bb + t;
        ans.data.push_back(num % 10);
        t = num / 10;
    }
    if (t > 0)
        ans.data.push_back(t);
    return ans;
}

ostream &operator<<(ostream &out, const BigInteger &n)
{
    long long int length = n.getLength();
    if (length == 0)
    {
        out << 0;
    }
    else
    {
        if(!n.sign){
            cout<<'-';
        }
        for (int i = length - 1; i >= 0; i--)
        {
            out << n.data[i];
        }
    }
    return out;
}

int main()
{
    // BigInteger a = 90;
    // BigInteger b = string("10");
    // cout << a + b << endl;
    int a = numeric_limits<int>::min();
    cout<<a*-1;
    return 0;
}