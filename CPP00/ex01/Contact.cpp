/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:05 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:47:12 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::setFirstName(std::string fisrtname){
	this->_firstName = fisrtname;
	return;
}
void	Contact::setLastName(std::string lastname){
	this->_lastName = lastname;
	return;
}
void	Contact::setNickName(std::string nickname){
	this->_nickName = nickname;
	return;
}
void	Contact::setPhoneNumber(std::string phonenumber){
	this->_phoneNumber = phonenumber;
	return;
}
void	Contact::setDarkestSecret(std::string dSecret){
	this->_darkestSecret = dSecret;
}

std::string	Contact::getFirstName(void){
	return(this->_firstName);
}
std::string	Contact::getLastName(void){
	return(this->_lastName);
}
std::string	Contact::getNickName(void){
	return(this->_nickName);
}
std::string	Contact::getPhoneNumber(void){
	return(this->_phoneNumber);
}
std::string	Contact::getDarkestSecret(void){
	return(this->_darkestSecret);
}