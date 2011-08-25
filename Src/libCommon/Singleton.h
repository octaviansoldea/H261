#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton {
private:
	static T m_instance;
public:
	static T *instance(void) { return &m_instance; }
};

template <class T>
T Singleton<T> :: m_instance; 


#endif /* SINGLETON_H */
