/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NICK.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wperu <wperu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:56:07 by wperu             #+#    #+#             */
/*   Updated: 2022/02/17 15:35:38 by wperu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commands.hpp"

class nick : public commands
{
    private:
        bool _checknick(std::string user, std::vector<Client *> *clients);
        bool _validnick(std::string nick);
        bool _is_informed(Client *dest, std::vector<Client *> informed);
        void _announcement_new_nick(std::string message, Client *cli,std::vector<Channel > *chan,std::vector<pollfd> &fds);
        
    public:
        nick();
        ~nick();
        void excute(std::string buf, Client *cli, std::vector<Channel> *chan, std::vector<Client *> *Clients,std::vector<pollfd> &fds);
        
    
};