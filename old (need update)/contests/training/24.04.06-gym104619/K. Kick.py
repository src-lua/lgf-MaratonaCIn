def main():
    s = input()
    i = 0; c = 0
    while s.find("kick", i) != -1:
        i = s.find("kick", i) + 3
        c += 1

    print(c)

    return 1


main()  # Start the program execution
