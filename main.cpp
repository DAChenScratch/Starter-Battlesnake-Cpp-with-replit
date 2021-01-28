
//Check the http_stuff for credits

#include <iostream>
#include "./http_stuff.h"
using namespace std;
int main(void) {
  cout << "Server waking up...";
  httplib::Server svr;
  svr.Get("/", [](const auto &, auto &res) {
    string head = "default"; //TODO: Customize
    string tail = "default"; //TODO: Customize
    string author = ""; //TODO: Customize
    string color = "#888888"; //TODO: Customize
    res.set_content("{\"apiversion\":\"1\", \"head\":\"" + head + "\", \"tail\":\"" + tail + "\", \"color\":\"" + color + "\", " + "\"author\":\"" + author + "\"}", "text/json");
  });
  svr.Post("/move", [](auto &req, auto &res){
    //get json data
    string data = req.body;
    cout << "\n\n" + data;
    string moves[4] = {"up", "down", "left", "right"};
    //TDO: Make some snake logic
    string move = "right";
    res.set_content("{\"move\": \"" + move + "\"}", "text/plain");
  });
  svr.Post("/end", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });
  svr.Post("/start", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });
  svr.listen("0.0.0.0", 8080);
}
