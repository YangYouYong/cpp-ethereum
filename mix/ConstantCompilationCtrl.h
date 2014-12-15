/*
	This file is part of cpp-ethereum.
	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file ConstantCompilation.h
 * @author Yann yann@ethdev.com
 * @date 2014
 * Ethereum IDE client.
 */

#pragma once

#include <QTextDocument>
#include "ConstantCompilationModel.h"
#include "Extension.h"

namespace dev
{
namespace mix
{

class ConstantCompilationCtrl: public Extension
{
	Q_OBJECT

public:
	ConstantCompilationCtrl(QTextDocument*);
	~ConstantCompilationCtrl() {}
	void start() const override;
	QString title() const override;
	QString contentUrl() const override;

private:
	QTextDocument* m_editor;
	std::unique_ptr<ConstantCompilationModel> m_compilationModel;
	void writeOutPut(CompilerResult const&);
	void resetOutPut();

public slots:
	void compile();
};

}

}
