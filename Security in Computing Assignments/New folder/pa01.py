#Assignment: pa01 - Encrypting a plaintext file using Vigenere cipher

#Author: Marin Aske
#Language: python

#To Execute: python -> python3 pa01.py kX.txt pX.txt
#Note: All input files are simple 8 bit ASCII input

#Class: CIS3360 - Security in Computing - Spring 2023
#Instructor: McAlpin
#Due Date: 3/6/2023

import sys
import numpy as np 

#Command Line Argument to define encryption key file (k1.txt file)
def read_key_materials(file):
  n = int(file.readline().strip())
  matrix = []
  for i in range(n):
    matrix.append([int(x) for x in file.readline().strip().split()])
  return np.array(matrix)
  
#Command Line Argument to define the plaintext file that is to be encrypted (p1.txt file)
def read_plaintext(file):
  plaintext = ''
  for line in file: 
      plaintext += line.strip().lower()
      plaintext = '', join([x for x in plaintext if x.isalpha()])
      while len(plaintext) % n !=0:
        plaintext += 'x'
      return plaintext
    
#Command to create encryption function
def encrypt(plaintext, key_matrix):
  n = key_matrix.shape[0]
  blocks = [plaintext[i:i+n] for i in range (0, len(plaintext), n)]
  ciphertext = ''
  for blocks in blocks:
    block_matrix = np.array([ord(x) - ord('a') for x in block]).reshape(n, 1)
    encrypted_block = np.dot(key_matrix, block.matrix) % 26
    ciphertext += ''.join([chr(x + ord('a')) for x in encrypted_block.flatten()])
  return ciphertext
  
  #Main function that calls the 3 previous functions and prints the output
  def main():
    if len(sys.argv) !=3:
      print('Usage: python pa01.py key_file plaintext_file')
      sys.exit(1)
    key_file = open(sys.argv[1], 'r')
    plaintext_file = open(sys.argv[2], 'r')
    
    #prints all inputs
    print('Key Matrix: ')
    print(key_matrix)
    print('Plaintext: ')
    print(plaintext)
    
    #calls encryption function to encrypt the inputs from the files
    ciphertext = encrypt(plaintext, key_matrix)
    print('Ciphertext: ')
    
    #sets character limit to 80
    for i in range(0, len(ciphertext), 80):
      print(ciphertext[i:i+80])
      
  if __name__ == "__main__":
    main()