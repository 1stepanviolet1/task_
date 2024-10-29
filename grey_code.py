

def non_cyclic_right_shift(number: int, shift: int = 1) -> int:
    if number == 0:
        return 0

    if number < 0:
        raise ValueError("Число должно быть неотрицательным")
    
    shifted_number = number >> shift
    mask = (1 << (number.bit_length() - shift)) - 1
    
    return shifted_number & mask


def grey_code(x: int) -> int:
    return x ^ non_cyclic_right_shift(x)


def reverce_grey_code(x: int) -> int:
    if x == 0:
        return 0

    if x < 0:
        raise ValueError("Число должно быть неотрицательным")
    
    num_of_bit = x.bit_length() - 1
    n = (x >> num_of_bit) & 1
    
    prev_bit = n
    while num_of_bit:
        num_of_bit -= 1
        bit = (x >> num_of_bit) & 1
        g_bit = bit ^ prev_bit
        n *= 0b10
        n += g_bit
        prev_bit = g_bit

    return n


if __name__ == '__main__':
    for i in range(8):
        print(f"{bin(grey_code(i))[2:]:0>2}")

    # print()

