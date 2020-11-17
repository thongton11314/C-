#ifndef _HASHNODE_
#define _HASHNODE_

template <typename Key, typename Val>
class HashNode {
public:

    // constructor
    HashNode(const Key & key, Val * val);

    // copy constructor
    HashNode(const HashNode &);

    // deconstructor
    // delete pointer val
    ~HashNode();

    // setter
    void setKey(const Key & key);
    void setVal(Val * val);
    //void setNext(Hashnode* next);

    // getter
    int getKey() const;
    Val * getVal() const;
    HashNode * getNext() const;
    
private:
    Key key;
    Val * value;
    HashNode* next;
};

// implementaion go down here

#endif //!_HASHNODE_