def count_substring(string, sub_string):
    return sum(1 for i in range(len(string)) if string.startswith(sub_string,i))



if __name__ == '__main__':
    string = input().strip() #ABCDCDC
    sub_string = input().strip() #CDC
    count = count_substring(string, sub_string)
    print(count) # 2 

