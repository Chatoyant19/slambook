#include <iostream>
#include <memory>

void testFun();

class Girl;

class Boy {
 public:
  Boy() { std::cout << "Boy construct" << std::endl; }
  ~Boy() { std::cout << "~Boy deconstruct" << std::endl; }

  void setGirlFriend(std::shared_ptr<Girl> _girlFriend) {
    this->girlFriend = _girlFriend;

    std::shared_ptr<Girl> sp_girl;
    sp_girl = this->girlFriend.lock();

    std::cout << "1:" << sp_girl.use_count() << std::endl;
    sp_girl = nullptr;
    std::cout << "2:" << sp_girl.use_count() << std::endl;
  }

 private:
  // std::shared_ptr<Girl> girlFriend;
  // 用weak_ptr,因为weak_ptr不会改变引用计数的大小，
  // 从而避免了因为shared_ptr交叉使用引用计数无法减到０进而无法析构内存的情况。
  std::weak_ptr<Girl> girlFriend;
};

class Girl {
 public:
  Girl() { std::cout << "Girl construct" << std::endl; }
  ~Girl() { std::cout << "~Girl deconstruct" << std::endl; }

  void setBoyFriend(std::shared_ptr<Boy> _boyFriend) {
    this->boyFriend = _boyFriend;


  }

 private:
  std::shared_ptr<Boy> boyFriend;
};

void testFun() {
  std::shared_ptr<Boy> spBoy(new Boy());
  std::shared_ptr<Girl> spGirl(new Girl());

  spBoy->setGirlFriend(spGirl);
  spGirl->setBoyFriend(spBoy);

  std::cout << spGirl.use_count() << std::endl;
  std::cout << spBoy.use_count() << std::endl;
}

int main(int argc, char** argv) {
  testFun();
  return 0;
}