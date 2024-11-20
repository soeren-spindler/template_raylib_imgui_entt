#ifndef _APPLICATION_H_
#define _APPLICATION_H_

namespace brkt {

class Application {
 public:
  Application();
  ~Application();

  bool Initialize();
  int Run();
};

}  // namespace brkt

#endif  // _APPLICATION_H_
