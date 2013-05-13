
#ifndef DATABASE_H
#define DATABASE_H

#include<sqlite3.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <class DataObject>
class Database {
	private:
		sqlite3 *dbConnection;
	public:
		Database<DataObject>(char* databaseFileName);
		~Database<DataObject>();
		vector<DataObject> doQuery(char* queryString);
};

using namespace std;

template <class DataObject>
Database<DataObject> :: Database(char* databaseFileName) {
	int result = sqlite3_open(databaseFileName, 
			&(this -> dbConnection));
	
	cout << "Connection to " <<  databaseFileName;

	if (result == SQLITE_OK) {
		cout << " successful." << endl;	
	} else {
		cout << " failed." << endl;
	}
}

template <class DataObject>
Database<DataObject>:: ~Database() {
	sqlite3_close(dbConnection);
	cout << "connection successfully closed." << endl;
}


using namespace std;
template <class DataObject>
vector<DataObject> Database<DataObject> ::doQuery(char* queryString) {
	//cout << "began.." << endl;
	vector<DataObject> results;
	//cout << "went here" << endl;
	sqlite3_stmt *statement;
	//cout << "querying..." << endl;

	if (sqlite3_prepare_v2( this -> dbConnection, 
				queryString,	
				-1, &statement, 0)== SQLITE_OK) {
		//cout << "query successful" << endl;	
		int num_columns = sqlite3_column_count(statement); 
	
		while(true) {
			//cout << "true" << endl;
			int result = sqlite3_step(statement);

			if (result == SQLITE_ROW) {
				char* columns[num_columns];
				for(int i = 0; i < num_columns; i++) {
					columns[i] = (char*)sqlite3_column_text(statement										, i); 						
				}
				DataObject newObject(columns, 3);
				results.push_back(newObject);
			} else {
				break;
			}
		}
	} else {
		cout << "query failed" << endl;
	}
	return results;
}


#endif
