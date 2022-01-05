/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wperu <wperu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:11:39 by wperu             #+#    #+#             */
/*   Updated: 2022/01/05 16:44:04 by wperu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "ircserver.hpp"

class commands
{
    protected:
        Channel* _check_chan(std::string name, std::vector<Channel *> *chan) const;
        bool     _check_client(Client *user, Channel *chan);
    public:
        commands();
        virtual ~commands();
};


