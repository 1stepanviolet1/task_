from math import ceil


def calculate_optimal_node_size(num_elements):
    INT_SIZE = 4
    MIN_CACHE_LINE = 64
    
    all_memory = num_elements * INT_SIZE
    cnt_cache_lines = ceil(all_memory / MIN_CACHE_LINE) 
    
    
    return cnt_cache_lines + 1


class Node:
    def __init__(self, data, *, _next=None):
        self.data = data
        self.next = _next
    
    def __repr__(self):
        return ' '.join(map(str, self.data))

    def append(self, el):
        return self.data.append(el)

    def __len__(self):
        return len(self.data)
    
    def pop(self, _index):
        return self.data.pop(_index)


class ExtandedLinkedList:
    def __init__(self, _iter):
        tmp_list = [el for el in _iter]
        if not tmp_list:
            self.head = None
            return
        
        self.node_size = calculate_optimal_node_size(len(tmp_list))
        
        self.head = Node([])
        
        it1 = iter(tmp_list)
        it2 = iter(tmp_list)
        i = 0
        
        for el in it1:
            if i >= self.node_size:
                break
            self.head.append(el)
            i += 1
            next(it2)
        
        cur_node = self.head
        for el in it2:
            if not (i % self.node_size):
                cur_node.next = Node([])
                cur_node = cur_node.next
            
            cur_node.append(el)
            i += 1
    
    def __repr__(self):
        res = ""

        if self.head is not None:
            res += f"Node {0}: {self.head}"
        else:
            return res

        cur_node = self.head.next
        i = 1
        
        while cur_node is not None:
            res += f"\nNode {i}: {cur_node}"
            cur_node = cur_node.next
            i += 1
        
        return res

    def search(self, needful_el) -> int:
        i = 0
        if self.head is None:
            return -1
        
        cur_node = self.head
        while cur_node is not None:
            for el in cur_node.data:
                if el == needful_el:
                    return i
                i += 1

            cur_node = cur_node.next
        
        return -1
    
    def pop(self, _pop_index):
        cur_node = self.head

        i = 0
        arr = []
        pop_el = None
        while cur_node is not None:
            for j, el in enumerate(cur_node.data):
                if i == _pop_index:
                    pop_el = cur_node.data[j]
                    i += 1
                    continue

                arr.append(el)
                i += 1

            cur_node = cur_node.next
        
        if pop_el is None:
            raise IndexError("pop index out of range")
        
        self.__init__(arr)
        return pop_el

    def __len__(self):
        size = 0

        cur_node = self.head
        while cur_node is not None:
            for _ in cur_node.data:
                size += 1

            cur_node = cur_node.next

        return size

    def insert(self, _ins_el, *, index):
        cur_node = self.head
        el_is_inserted = False
        i = 0
        arr = []
        while cur_node is not None:
            for el in cur_node.data:
                if i == index:
                    el_is_inserted = True
                    arr.append(_ins_el)
                    i += 1

                arr.append(el)
                i += 1

            cur_node = cur_node.next
        
        if not el_is_inserted:
            arr.append(_ins_el)

        self.__init__(arr)


ex_list = ExtandedLinkedList(int(el) for el in input().split())

print(ex_list)
print()
print(ex_list.pop(3))
print(ex_list.pop(5))
print()
print(ex_list)

