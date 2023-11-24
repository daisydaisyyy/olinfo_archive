#include <map>
using namespace std;
map <long long int,long long int> l;

void aggiungi(long long int id) {  
		auto i=l.find(id);
		if(i->first==id){
			i->second++;
		}else{
			l.emplace(id,1);
		}
}

void togli(long long int id) {
    //std::map<long long int,int>:: iterator i;
	auto i=l.find(id);
	if(i->first==id&&i->second!=0){
		i->second--;
	}
}

long long int conta(long long int id) {
		auto i=l.find(id);
		if(i->first==id){
			return i->second;
		}
		return 0;
}
