struct KeyTableEntry {
    unsigned int bit_length;
    unsigned int data;
};

struct KeyTable {
    struct KetTableEntry* table;
};

struct KeyTable create_key_table();

void destroy_key_table(struct KeyTable table);

unsigned int lookup_bit_length(struct KeyTable table, char byte);

unsigned int lookup_table_value(struct KeyTable table, char byte);

void set_key_table_value(struct KeyTable table, char byte, unsigned int data, unsigned int bit_length);