#include <map>
#include <queue>
#include <chrono>
#include <string>
#include <iostream>

struct HuffmanNode
{
   char ch;
   int freq;
   HuffmanNode *left;
   HuffmanNode *right;
};

struct CompareNodes
{
   bool operator()(const HuffmanNode *a, const HuffmanNode *b) const
   {
      return a->freq > b->freq;
   }
};

static void generateCodes(HuffmanNode *node, std::map<char, std::string> &codes, const std::string &prefix = "")
{
   if (!node)
      return;
   if (!node->left && !node->right)
   {
      codes[node->ch] = prefix.empty() ? "0" : prefix;
      return;
   }
   generateCodes(node->left, codes, prefix + "0");
   generateCodes(node->right, codes, prefix + "1");
}

static void freeTree(HuffmanNode *node)
{
   if (!node)
      return;
   freeTree(node->left);
   freeTree(node->right);
   delete node;
}

static std::map<char, std::string> huffmanCoding(const std::map<char, int> &frequencies)
{
   std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, CompareNodes> minHeap;

   for (const auto &kv : frequencies)
   {
      HuffmanNode *node = new HuffmanNode{kv.first, kv.second, nullptr, nullptr};
      minHeap.push(node);
   }

   if (minHeap.empty())
      return {};

   while (minHeap.size() > 1)
   {
      HuffmanNode *left = minHeap.top();
      minHeap.pop();
      HuffmanNode *right = minHeap.top();
      minHeap.pop();

      HuffmanNode *merged = new HuffmanNode{'\0', left->freq + right->freq, left, right};
      minHeap.push(merged);
   }

   HuffmanNode *root = minHeap.top();
   std::map<char, std::string> codes;
   generateCodes(root, codes);
   freeTree(root);
   return codes;
}

int main()
{
   std::map<char, int> frequencies;
   frequencies['A'] = 5;
   frequencies['B'] = 9;
   frequencies['C'] = 12;
   frequencies['D'] = 13;
   frequencies['E'] = 16;
   frequencies['F'] = 45;

   std::cout << "Building Huffman Tree and Generating Codes..." << std::endl;

   auto start = std::chrono::high_resolution_clock::now();
   auto codes = huffmanCoding(frequencies);
   auto end = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
   for (const auto &kv : codes)
   {
      std::cout << kv.first << ": " << kv.second << std::endl;
   }
   std::cout << "\nTime taken: " << duration << " microseconds" << std::endl;
   return 0;
}
