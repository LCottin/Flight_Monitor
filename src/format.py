'''
This file is used to replace , with space
'''

from sys import argv

def main(path, new_path):
    '''
    This is the main function
    '''
    with open(path, "r+") as file:
        with open(new_path, "w+") as new_file:
            for line in file:
                line = line.replace(",", " ")
                new_file.write(line)
                
    print("Done")
    return 

if __name__ == "__main__":
    main(argv[1], argv[2])