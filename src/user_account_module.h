#include "common.h"
class Core;
class UserAccountModule
{
private:
  Core * m_pCore;
public:
  UserAccountModule(Core * core)
  {
      m_pCore = core;
  }
  void AddUser(user_t u);
  void UpdateUser(user_t u);
};
