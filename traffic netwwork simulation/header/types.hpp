#pragma once
#include <string>
#include <stdexcept> 
 
 namespace map_types{
 	enum class lo_type{
 		TOURIST_ATTRACTION,
 		LANDMARK,
 		RESTAURANT,
 		OTHERS,
 		UNDEFINED //gia tri mac dinh xu ly loi 
	};
	
	enum class direction{
		east, //dong
		west, //tay
		south, //nam
		north //bac
	};
	
	//lo_type enum -> string 
	inline std::string to_string (lo_type t){
		switch (t){
			case lo_type::TOURIST_ATTRACTION:
				return "Diem tham quan";
			case lo_type::LANDMARK:
				return "Landmark";
			case lo_type::RESTAURANT:
				return "Quan an";
			case lo_type::OTHERS:
				return "Khac";
			case lo_type::UNDEFINED:
				return "Khong xac dinh";
		}
		return "UNKNOWN_TYPE"; // idk chac loi gi do
	}
	
	//string -> enum lo_type
	inline lo_type to_enum(const std::string &str)
		if(str == "Diem tham quan" || str == "diem tham quan")
			return lo_type::TOURIST_ATTRACTION;
			
		else if(str == "Landmark" || str == "landmark")
			return lo_type::LANDMARK;
		
		else if(str == "Quan an" || str == "quan an")
			return lo_type::RESTAURANT;
		
		else if(str == "Khac" || str == "khac")
			return lo_type::OTHERS;
		
		else
			throw std::invalid_argument ("Loai dia diem k hop le: " + str);
	} 
	
 }
