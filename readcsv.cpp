#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

struct Item{
	string id;
	string attribute_name;
	string attribute_value;
};
Item* Parse_string(string s);

int main(int argc,char *argv[]){
	if(argc==1){	
	ifstream csv(argv[1]);
	string line;
	if(csv.good()){
		if(csv.is_open()){
			while(getline(csv,line)){
				Item *item2=new Item();
				item2=Parse_string(line);
			}
		}
		csv.close();
	}
	string s("1,y7677,b 67");
	Item *item2=new Item();
	item2=Parse_string(s);
	cout<<"Item2"<<endl;
	cout<<item2->attribute_name<<" "<<item2->attribute_value<<" "<<item2->id<<endl;
	//if(item2)
	//	cout<<s<<endl;
}
	return 0;
}
Item* Parse_string(string s){
	int pos=0;
	pos=s.find(",");
    string token = s.substr(0, pos);
    //struct item item1=malloc(sizeof(struct item));
    Item *item1=new Item();
    /*if(!item1){
    	//printf("Memory error\n");
    	cout<<"Memory error"<<endl;
    	return 0;
	}*/	cout<<"parse function"<<endl;
	cout<<token<<endl;
	item1->id=token;
    std::cout << item1->id << std::endl;
    s.erase(0, pos +1);
    pos=s.find(",");
    item1->attribute_name=s.substr(0,pos);
    cout<<item1->attribute_name<<endl;
	s.erase(0, pos +1);
	if(pos=s.find(",")){
		item1->attribute_name=s.substr(0,pos);
		cout<<item1->attribute_value<<endl;
	}
	else{
		item1->attribute_name=s;
		cout<<item1->attribute_value<<endl;
	}	
	cout<<s<<endl;
	return item1;
}	
