
//Check the http_stuff for credits

#include <iostream>
#include "./http_stuff.h"
using namespace std;
int main(void) {
  cout << "Server waking up...";
  httplib::Server svr;
  //Get /, that is how the battlesnake engine will customize your snake.
  svr.Get("/", [](const auto &, auto &res) {
    string head = "default"; //TODO: Customize
    string tail = "default"; //TODO: Customize
    string author = ""; //TODO: Customize
    string color = "#888888"; //TODO: Customize (any hex color)
    res.set_content("{\"apiversion\":\"1\", \"head\":\"" + head + "\", \"tail\":\"" + tail + "\", \"color\":\"" + color + "\", " + "\"author\":\"" + author + "\"}", "text/json");
  });
  //Sent by the battlesnake engine when it needs you to move
  svr.Post("/move", [](auto &req, auto &res){
    //get json data
    string data = req.body;
    cout << "\n\n" + data;
    string moves[4] = {"up", "down", "left", "right"};
    //TODO: Make some snake logic
    string move = "right";
    res.set_content("{\"move\": \"" + move + "\"}", "text/plain");
  });
  //Purely functional, useful if you have a stateful snake
  svr.Post("/end", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });
  //Also purely functional unless you have a stateless snake.
  svr.Post("/start", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });
  //Listen on host 0.0.0.0 and port 8080
  //Repl.it http servers will only run if the host is 0.0.0.0
  svr.listen("0.0.0.0", 8080);
}
