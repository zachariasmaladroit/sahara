/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of sahara.
* 
* sahara is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* sahara is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with sahara. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_image_transfer_task.h
* @class SaharaMemoryReadTask
* @package openpst/sahara
* @brief Handles thememory reading threaded task operation
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include "task/task.h"
#include "qualcomm/sahara_serial.h"
#include "widget/progress_group_widget.h"

using OpenPST::QC::SaharaSerial;
using OpenPST::QC::SaharaSerialError;
using OpenPST::Serial::SerialError;

namespace OpenPST {
	namespace GUI {
		class SaharaMemoryReadTask : public Task
		{
			private:
				uint32_t	address;
				size_t		size;
				std::string outFile;
				SaharaSerial& port;
				ProgressGroupWidget* progressContainer;

			public:
				SaharaMemoryReadTask(uint32_t address, size_t size, std::string outFile, ProgressGroupWidget* progressContainer, SaharaSerial& port);
				~SaharaMemoryReadTask();
				void run();
		};
	}
}
