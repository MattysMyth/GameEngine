#ifndef VAO_H
#define VAO_H

namespace Engine
{
	struct VAO
	{
		VAO();
		~VAO();

		void bind();
		void unbind();

		unsigned int getID();

	private:
		unsigned int id;
	};
}

#endif // !VAO_H