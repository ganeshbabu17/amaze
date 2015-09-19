#include "C:\\amazon\\MySQL Connector C++ 1.1.6\\include\\mysql_connection.h"

#include "C:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.6\\include\\msql_driver.h"
#include "C:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.6\\include\\cppconn\\exception.h"
#include "C:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.6\\include\\cppconn\\resultset.h"
#include "C:\\Program Files\\MySQL\\MySQL Connector C++ 1.1.6\\include\\cppconn\\statement.h"
#include<iostream>

using namespace std;

int main(void)
{
cout << endl;
cout << "Running 'SELECT 'Hello World!'   AS _message'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://192.168.11.69:3306", "root", "Praveen1");
  /* Connect to the MySQL test database */
  con->setSchema("test");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("_message") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column fata by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }
  delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}
