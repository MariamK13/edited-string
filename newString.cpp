#include <iostream>

class STR {
	size_t m_size;
	size_t m_cap;
	char* m_ptr;
public:
	STR();
	void print();
	char& at(int);
	size_t size();
	size_t capacity();
	void reserve();
	void shrink_to_fit();
	bool empty();
	void clear();
	void push_back(char val);
	void pop_back();
	void insert(char val, int pos);
    char& front();
    char& back();
    const char* c_str();
    void erase(int pos, int count);
    void erase(int pos);
   // void append();
   // char* substr();
   // char* copy();
   // void resize();
   // void swap();
   // char* find();
   // void to_string();
   // void stoi();
	~STR();
};

STR::STR()
{
	m_size = 0;
	m_cap = 0;
	m_ptr = nullptr;
}
void STR::clear()
{
	if (m_ptr != nullptr) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = 0;
		m_cap = 0;
	}
}

size_t STR::size()
{
	return m_size;
}

size_t STR::capacity()
{
	return m_cap;
}

void STR::print()
{
	if (m_ptr != nullptr) {
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_ptr[i];
		}
	}
}

char& STR::at(int pos)
{   
	if (pos < 0 || pos >= m_size) {
		std::cout << "no way";
	}
	return m_ptr[pos];
}

void STR::pop_back()
{
	if (m_size > 0) {
	--m_size;
	}
}

void STR::reserve()
{
	if (m_cap == 0) {
		m_cap = 8;
		m_ptr = new char[m_cap];
	}
	m_cap *= 2;
	char* tmp = new char[m_cap];
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_ptr[i];
	}
	delete []m_ptr;
	m_ptr = tmp;
	tmp = nullptr;
}

void STR::push_back(char val)
{
	if (m_ptr == nullptr || m_size == m_cap) {
		reserve();
	}
	m_ptr[m_size] = val;
	++m_size;	
}

void STR::shrink_to_fit()
{
	if (m_size < m_cap) {
	char* tmp = new char[m_size];
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_ptr[i];
		}
	m_cap = m_size;
	delete [] m_ptr;
	m_ptr = tmp;
	tmp = nullptr;
	}
}

bool STR::empty()
{
	if (m_ptr == nullptr) {
		return true;
	}
	return false;
}

void STR::insert(char val, int pos)
{
	if (pos < 0 || pos >= m_size) {
	std::cout << "no way";
	}
	if (m_size == m_cap) {
	reserve();
	}
	int index = m_size;
	m_size += 1;
	while (index != pos) {
		m_ptr[index] = m_ptr[index - 1];
		--index;
		}
	m_ptr[pos] = val;
}

char& STR::front()
{
    if (empty()) {
        std::cout << "no way";
    } 
        return m_ptr[0];
}

char& STR::back()
{
    if (empty()) {
    std::cout << "no way";
    }
    return m_ptr[size() - 1];
}

const char* STR::c_str()
{
    if (m_size == m_cap) {
        reserve();  
    }
    m_size += 1;
    char* tmp = new char[m_size];
    for (int i = 0; i < m_size - 1; ++i) {
        tmp[i] = m_ptr[i];
    }
    tmp[m_size - 1] = '\0';
    delete [] m_ptr;
    m_ptr = tmp;
    tmp = nullptr;
    return m_ptr;
}

void STR::erase(int pos, int count)
{
    if (pos < 0 || pos >= m_size || count > m_ptr[m_size - pos]) {
        std::cout << "no way";
    } else {
        for (int i = pos; i < m_size - count; ++i) {
            std::swap(m_ptr[i], m_ptr[i + count]);
            
        }
        m_size -= count;
    }
    
}
void STR::erase(int pos)
{
    if (pos < 0 || pos >= m_size) {
        std::cout << "no way";
        } else if (pos == m_size - 1) {
        --m_size;
        } else {
            for (int i = pos; i < m_size - 1; ++i) {
                std::swap(m_ptr[i], m_ptr[i + 1]);
            }
            --m_size;
        }
}

STR::~STR() 
{
	clear();
}

int main()
{
	STR A;
//	std::cout << A.capacity();
	A.push_back('c');
	A.push_back('d');
	A.push_back('e');
	A.push_back('f');
	A.push_back('g');
	A.print();	
	std::cout << std::endl;
	A.insert('a', 2);
	A.print();
	std::cout << std::endl;
//	A.at(2) = 'M';
//	A.print();
//	A.pop_back();
//	A.print();
	std::cout << std::endl;
	std::cout << A.empty();
	std::cout << A.capacity() << std::endl;
	A.shrink_to_fit();
	std::cout << A.capacity() << std::endl;
	A.print();
    std::cout << std::endl;
   // std::cout << A.front() << std::endl;
   // std::cout << A.back() << std::endl;
   // std::cout << A.c_str() << std::endl;
   // A.erase(3);
   // A.print();
    std::cout << std::endl;
    A.erase(3, 2);
    A.print();
    std::cout << std::endl;
	
}
