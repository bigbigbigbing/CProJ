

#include <stdio.h>
#include <json-c/json.h>

void parse_json(const char *json_str) 
{
	struct json_object *root = json_tokener_parse(json_str);

	if (json_object_get_type(root) == json_type_object) 
	{
		struct json_object *scan_freq_list;
		if (json_object_object_get_ex(root, "scan_freq_list", &scan_freq_list)) 
		{
			int array_len = json_object_array_length(scan_freq_list);

			for (int i = 0; i < array_len; ++i) 
			{
				struct json_object *element = json_object_array_get_idx(scan_freq_list, i);

				struct json_object *rat, *scan_freqs;
				if (json_object_object_get_ex(element, "rat", &rat) &&
						json_object_object_get_ex(element, "scan_freqs", &scan_freqs)) 
				{

					printf("Network Type: %s\n", json_object_get_string(rat));

					int freq_array_len = json_object_array_length(scan_freqs);
					printf("Scanned Frequencies:\n");

					for (int j = 0; j < freq_array_len; ++j) 
					{
						struct json_object *freq = json_object_array_get_idx(scan_freqs, j);
						printf("%d\n", json_object_get_int(freq));
					}
					printf("\n");
				}
			}
		}
	}

	json_object_put(root);
}

int main() {
	const char *json_str = "{ \"scan_freq_list\": [ { \"rat\": \"NR\", \"scan_freqs\": [504990, 627264, 633984] }, { \"rat\": \"LTE\", \"scan_freqs\": [1300, 1650, 1850, 2452, 38400, 40936] } ] }";

	// Parse and print the JSON
	parse_json(json_str);

	return 0;
}


