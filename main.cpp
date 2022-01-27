#include "utils/Logger.hpp"
#include <duckdb.hpp>
#include <iostream>

int main() {
  using namespace grok;
  using namespace std;
  using namespace duckdb;
  glog.info("Starting the application");
  DuckDB db(nullptr);
  Connection con(db);
  // create a table
  con.Query("CREATE TABLE integers(i INTEGER, j INTEGER)");
  // insert three rows into the table
  con.Query("INSERT INTO integers VALUES (3, 4), (5, 6), (7, NULL)");
  auto res = con.Query("SELECT * FROM integers");
  auto& result = *res;
  if (!result.success) {
    glog.error("{}", result.error);
  } else {
    glog.info("\n{}", result.ToString());
  }

  return 0;
}
