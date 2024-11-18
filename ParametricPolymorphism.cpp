template<typename T>
vector<T> Filter(vector<T> data, function <bool (const T&)> func)
    {
        
      vector<T> retList;
      // iterate  
      for (auto name: data)
        {
            // invoke predicate
            if (func (name))
               // aggregate result 
               retList.push_back(name);
        }
        // project the result
        return retList;        
    }

vector<int> numbers={1,2,3,4,5};
std:function<bool(const int& )> func=[](int item)->bool { return %2==0;};
vector<int> result=Filter<int>(numbers,func);

vector<string> names={"Bosch","Blr","Cat","Cow"};
std:function<bool(const string& )> stringFunc=[](string item)->bool { return item[0]=='B';};
vector<int> result=Filter<string>(names,stringFunc);
